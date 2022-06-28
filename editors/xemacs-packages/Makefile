# $NetBSD: Makefile,v 1.81 2022/06/28 11:33:49 wiz Exp $

DISTNAME=	xemacs-packages
PKGNAME=	xemacs-packages-1.18
PKGREVISION=	10

CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=${XEMACSPKG_PATH}/}
XEMACSPKG_PATH=	beta/experimental/packages
DISTFILES=	\
		Sun-1.19-pkg.tar.gz \
		ada-1.16-pkg.tar.gz \
		apel-1.36-pkg.tar.gz \
		auctex-1.56-pkg.tar.gz \
		bbdb-1.34-pkg.tar.gz \
		build-1.18-pkg.tar.gz \
		c-support-1.24-pkg.tar.gz \
		calc-1.28-pkg.tar.gz \
		calendar-1.41-pkg.tar.gz \
		cc-mode-1.99-pkg.tar.gz \
		cedet-common-1.03-pkg.tar.gz \
		clearcase-1.12-pkg.tar.gz \
		cogre-1.04-pkg.tar.gz \
		cookie-1.17-pkg.tar.gz \
		crisp-1.17-pkg.tar.gz \
		debug-1.20-pkg.tar.gz \
		dictionary-1.18-pkg.tar.gz \
		dired-1.22-pkg.tar.gz \
		docbookide-0.10-pkg.tar.gz \
		easypg-1.05-pkg.tar.gz \
		ecb-1.25-pkg.tar.gz \
		ecrypto-0.23-pkg.tar.gz \
		ede-1.06-pkg.tar.gz \
		edebug-1.24-pkg.tar.gz \
		edict-1.19-pkg.tar.gz \
		ediff-1.84-pkg.tar.gz \
		edit-utils-2.57-pkg.tar.gz \
		edt-1.16-pkg.tar.gz \
		efs-1.37-pkg.tar.gz \
		egg-its-1.29-pkg.tar.gz \
		eieio-1.09-pkg.tar.gz \
		elib-1.15-pkg.tar.gz \
		emerge-1.13-pkg.tar.gz \
		erc-0.26-pkg.tar.gz \
		escreen-1.03-pkg.tar.gz \
		eshell-1.20-pkg.tar.gz \
		ess-1.18-pkg.tar.gz \
		eterm-1.20-pkg.tar.gz \
		eudc-1.43-pkg.tar.gz \
		footnote-1.18-pkg.tar.gz \
		forms-1.17-pkg.tar.gz \
		fortran-modes-1.07-pkg.tar.gz \
		frame-icon-1.13-pkg.tar.gz \
		fsf-compat-1.24-pkg.tar.gz \
		games-1.23-pkg.tar.gz \
		general-docs-1.10-pkg.tar.gz \
		gnats-1.19-pkg.tar.gz \
		gnus-2.03-pkg.tar.gz \
		guided-tour-0.54-pkg.tar.gz \
		haskell-mode-1.14-pkg.tar.gz \
		hm--html-menus-1.26-pkg.tar.gz \
		hyperbole-1.22-pkg.tar.gz \
		ibuffer-1.12-pkg.tar.gz \
		idlwave-1.34-pkg.tar.gz \
		igrep-1.18-pkg.tar.gz \
		ilisp-1.38-pkg.tar.gz \
		ispell-1.37-pkg.tar.gz \
		jde-1.54-pkg.tar.gz \
		latin-euro-standards-1.11-pkg.tar.gz \
		latin-unity-1.23-pkg.tar.gz \
		locale-1.30-pkg.tar.gz \
		lookup-1.17-pkg.tar.gz \
		mail-lib-1.83-pkg.tar.gz \
		mailcrypt-2.16-pkg.tar.gz \
		mew-1.22-pkg.tar.gz \
		mh-e-1.35-pkg.tar.gz \
		mine-1.18-pkg.tar.gz \
		misc-games-1.25-pkg.tar.gz \
		mmm-mode-1.08-pkg.tar.gz \
		mule-base-1.60-pkg.tar.gz \
		mule-ucs-1.21-pkg.tar.gz \
		net-utils-1.61-pkg.tar.gz \
		ocaml-0.10-pkg.tar.gz \
		oo-browser-1.07-pkg.tar.gz \
		os-utils-1.44-pkg.tar.gz \
		pc-1.30-pkg.tar.gz \
		pcl-cvs-1.73-pkg.tar.gz \
		pcomplete-1.08-pkg.tar.gz \
		perl-modes-1.16-pkg.tar.gz \
		pgg-1.10-pkg.tar.gz \
		prog-modes-2.32-pkg.tar.gz \
		ps-print-1.14-pkg.tar.gz \
		psgml-1.49-pkg.tar.gz \
		psgml-dtds-1.05-pkg.tar.gz \
		python-modes-1.16-pkg.tar.gz \
		re-builder-1.07-pkg.tar.gz \
		reftex-1.36-pkg.tar.gz \
		riece-1.26-pkg.tar.gz \
		rmail-1.16-pkg.tar.gz \
		ruby-modes-1.07-pkg.tar.gz \
		sasl-1.18-pkg.tar.gz \
		scheme-1.22-pkg.tar.gz \
		semantic-1.23-pkg.tar.gz \
		sgml-1.13-pkg.tar.gz \
		sh-script-1.26-pkg.tar.gz \
		sieve-1.20-pkg.tar.gz \
		skk-1.27-pkg.tar.gz \
		slider-1.18-pkg.tar.gz \
		sml-mode-0.14-pkg.tar.gz \
		sounds-au-1.14-pkg.tar.gz \
		sounds-wav-1.14-pkg.tar.gz \
		speedbar-1.32-pkg.tar.gz \
		strokes-1.12-pkg.tar.gz \
		supercite-1.23-pkg.tar.gz \
		texinfo-1.32-pkg.tar.gz \
		text-modes-2.05-pkg.tar.gz \
		textools-1.17-pkg.tar.gz \
		time-1.16-pkg.tar.gz \
		tm-1.42-pkg.tar.gz \
		tooltalk-1.17-pkg.tar.gz \
		tpu-1.16-pkg.tar.gz \
		tramp-1.57-pkg.tar.gz \
		vc-1.50-pkg.tar.gz \
		vc-cc-1.24-pkg.tar.gz \
		vhdl-1.24-pkg.tar.gz \
		view-process-1.15-pkg.tar.gz \
		viper-1.69-pkg.tar.gz \
		vm-8.11-pkg.tar.gz \
		w3-1.41-pkg.tar.gz \
		x-symbol-1.16-pkg.tar.gz \
		xemacs-base-2.45-pkg.tar.gz \
		xemacs-devel-1.84-pkg.tar.gz \
		xetla-1.04-pkg.tar.gz \
		xlib-1.16-pkg.tar.gz \
		xslide-1.11-pkg.tar.gz \
		xslt-process-1.14-pkg.tar.gz \
		xwem-1.25-pkg.tar.gz \
		zenirc-1.18-pkg.tar.gz
### DISTFILES

# leim/hebrew.el causes build problems, we use stable package instead
#		leim-1.38-pkg.tar.gz \

DISTFILES+=	leim-1.31-pkg.tar.gz
SITES.leim-1.31-pkg.tar.gz= ${MASTER_SITE_XEMACS:=packages/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	https://www.xemacs.org/
COMMENT=	Common elisp packages for xemacs 21

DEPENDS+=	xemacs{,-nox11}>=21.1.14:../../editors/xemacs

DIST_SUBDIR=	${PKGBASE}
EXTRACT_DIR=	${WRKDIR}/${PKGBASE}

# cedet-common-1.03-pkg.tar.gz hard-links two files to themselves,
# which the default nbtar does not take well
EXTRACT_USING=	gtar

NO_BUILD=	yes

USE_TOOLS+=	printf pax find gawk gzip gtar
USE_TOOLS+=	perl:run

XEPKGDIR=	lib/xemacs/xemacs-packages

INSTALLATION_DIRS+=	${XEPKGDIR}

PKG_OPTIONS_VAR=	PKG_OPTIONS.xemacs-packages
PKG_SUPPORTED_OPTIONS+=	x11
PKG_SUGGESTED_OPTIONS+=	x11

.include "../../mk/bsd.options.mk"

# Only attempt to register fonts if we have X11 support (mkfontdir)
.if !empty(PKG_OPTIONS:Mx11)
FONTS_DIRS.x11+=	${PREFIX}/${XEPKGDIR}/etc/x-symbol/fonts
FONTS_DIRS.x11+=	${PREFIX}/${XEPKGDIR}/etc/x-symbol/origfonts
FONTS_DIRS.x11+=	${PREFIX}/${XEPKGDIR}/etc/x-symbol/pcf
.endif

REPLACE_PERL=		etc/bbdb/bbdb-areacode-split.pl
REPLACE_PERL+=		etc/bbdb/bbdb-cid.pl
REPLACE_PERL+=		etc/bbdb/bbdb-srv.pl
REPLACE_PERL+=		etc/bbdb/bbdb-unlazy-lock.pl
REPLACE_PERL+=		etc/erc/servers.pl
REPLACE_PERL+=		etc/idlwave/idlwave_catalog
REPLACE_PERL+=		etc/x-symbol/fonts/makesub
REPLACE_PERL+=		lisp/hyperbole/file-newer

# Do not depend on Python just for one file
CHECK_INTERPRETER_SKIP=	${XEPKGDIR}/etc/python-modes/pydoc_lisp.py

PRINT_PLIST_AWK+=	{ sub("\\.el$$", ".el$${ELSUFX}") }

.if defined(MANZ)
PLIST_SUBST+=	ELSUFX=.gz
.else
PLIST_SUBST+=	ELSUFX=
.endif

# XXX For package maintainance
#
# Usage: run `make PKG_DEVELOPER=1 xemacs-update-package'.  Makefile.work is
# generated.  If any package is updated, bump this package version, and commit.
.include "../../mk/bsd.prefs.mk"
.if defined(PKG_DEVELOPER) && ${OPSYS} == "NetBSD"
ED=		/bin/ed
FTP=		${TOOLS_PATH.ftp:Q}

# One of mk/fetch/sites.mk:MASTER_SITE_XEMACS
XEMACSPKG_SITE=	ftp://ftp.isr.tecnico.ulisboa.pt/pub/xemacs

# Make a list of packages from a directory list output
.PHONY: xemacs-make-package-list
xemacs-fetch-package-list:
	@${ECHO} ls | ${FTP} ${XEMACSPKG_SITE}/${XEMACSPKG_PATH}/ | \
	${AWK} '/-pkg\.tar\.gz/ { print $$9; }' \
		>${PKGDIR}/packages.list

# Merge package list data into Makefile
.PHONY: xemacs-merge-package-list
xemacs-merge-package-list:
	{ \
		${SED} '/^DISTFILES/q' ${PKGDIR}/Makefile; \
		${SED} 's|^|		|' ${PKGDIR}/packages.list; \
		${SED} -n '/^### DISTFILES/,$$p' ${PKGDIR}/Makefile; \
	} >${PKGDIR}/Makefile.work
	{ \
		${PRINTF} '/^DISTFILES\n+1\nka\n/^### DISTFILES\n-2\nkb\n'; \
		${PRINTF} "'a,'b"'s/$$/ \\\\/\nw\nq\n'; \
	} | ${ED} - ${PKGDIR}/Makefile.work

.PHONY: xemacs-update-package
xemacs-update-package: xemacs-fetch-package-list xemacs-merge-package-list
.endif	# defined(PKG_DEVELOPER) && ${OPSYS} == "NetBSD"

pre-configure:
	@${ECHO_MSG} "Fixing file permissions ... "
	${CHMOD} -R u+w,go-w ${WRKSRC}
	${CHMOD} g+r,o+r ${WRKSRC}/lisp/auctex/ChangeLog
	${CHMOD} ugo-x ${WRKSRC}/lisp/erc/ChangeLog.2005.upstream
	${FIND} ${WRKSRC} -type f -and -perm -100 \
		-and \( -name "*.el" -or -name "*.gif" -or -name "*.jar" \) \
		-exec ${CHMOD} ugo-x \{\} \+
	@${ECHO_MSG} "done"
.if empty(PKG_OPTIONS:Mx11)
	${RM} ${WRKSRC}/etc/x-symbol/pcf/fonts.dir
.endif
	@${ECHO_MSG} "Re-compiling patched elisp files ... "
	for ff in `cat ${PATCHDIR}/*.el | awk '/^\\+\\+\\+/ { print $$2 }'` ; do \
		${RM} -f ${WRKSRC}/$${ff}.orig ; \
		cd ${WRKSRC} && xemacs --vanilla --batch \
		--eval "(load-file \"${PKGDIR}/files/compile-el-file.el\")" \
		--eval "(compile-el-file \"${WRKSRC}/lisp\" \
			\"${WRKSRC}/$${ff}\")" ; \
	done
	@${ECHO_MSG} "done"
.if defined(MANZ)
	@${ECHO_MSG} "Compressing \".el\" source files ... "
	cd ${WRKSRC} && \
		${GREP} '\$${ELSUFX}$$' ${PLIST_SRC} | \
		${SED} -e "s#${XEPKGDIR}/##g" -e 's#\$${ELSUFX}$$##' | \
		${XARGS} ${GZIP_CMD}
	@${ECHO_MSG} "done"
.endif

do-install:
	cd ${WRKSRC} && pax -rw -l -pp . ${DESTDIR}${PREFIX}/${XEPKGDIR}

.include "../../mk/bsd.pkg.mk"
