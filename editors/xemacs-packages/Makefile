# $NetBSD: Makefile,v 1.67 2016/07/09 06:38:15 wiz Exp $

DISTNAME=	xemacs-packages
PKGNAME=	xemacs-packages-1.17
PKGREVISION=	2

CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=packages/}
DISTFILES=	\
		Sun-1.16-pkg.tar.gz \
		ada-1.14-pkg.tar.gz \
		apel-1.34-pkg.tar.gz \
		auctex-1.51-pkg.tar.gz \
		bbdb-1.32-pkg.tar.gz \
		build-1.15-pkg.tar.gz \
		c-support-1.22-pkg.tar.gz \
		calc-1.26-pkg.tar.gz \
		calendar-1.38-pkg.tar.gz \
		cc-mode-1.45-pkg.tar.gz \
		cedet-common-1.01-pkg.tar.gz \
		clearcase-1.10-pkg.tar.gz \
		cogre-1.02-pkg.tar.gz \
		cookie-1.15-pkg.tar.gz \
		crisp-1.15-pkg.tar.gz \
		debug-1.18-pkg.tar.gz \
		dictionary-1.16-pkg.tar.gz \
		dired-1.20-pkg.tar.gz \
		docbookide-0.08-pkg.tar.gz \
		easypg-1.03-pkg.tar.gz \
		ecb-1.22-pkg.tar.gz \
		ecrypto-0.21-pkg.tar.gz \
		ede-1.03-pkg.tar.gz \
		edebug-1.22-pkg.tar.gz \
		edict-1.17-pkg.tar.gz \
		ediff-1.81-pkg.tar.gz \
		edit-utils-2.43-pkg.tar.gz \
		edt-1.14-pkg.tar.gz \
		efs-1.34-pkg.tar.gz \
		egg-its-1.27-pkg.tar.gz \
		eieio-1.07-pkg.tar.gz \
		elib-1.13-pkg.tar.gz \
		emerge-1.11-pkg.tar.gz \
		erc-0.23-pkg.tar.gz \
		escreen-1.01-pkg.tar.gz \
		eshell-1.18-pkg.tar.gz \
		eterm-1.18-pkg.tar.gz \
		eudc-1.40-pkg.tar.gz \
		footnote-1.16-pkg.tar.gz \
		forms-1.15-pkg.tar.gz \
		fortran-modes-1.05-pkg.tar.gz \
		frame-icon-1.11-pkg.tar.gz \
		fsf-compat-1.19-pkg.tar.gz \
		games-1.20-pkg.tar.gz \
		general-docs-1.06-pkg.tar.gz \
		gnats-1.17-pkg.tar.gz \
		gnus-1.94-pkg.tar.gz \
		guided-tour-0.52-pkg.tar.gz \
		haskell-mode-1.11-pkg.tar.gz \
		hm--html-menus-1.24-pkg.tar.gz \
		hyperbole-1.17-pkg.tar.gz \
		ibuffer-1.10-pkg.tar.gz \
		idlwave-1.32-pkg.tar.gz \
		igrep-1.16-pkg.tar.gz \
		ilisp-1.36-pkg.tar.gz \
		ispell-1.32-pkg.tar.gz \
		jde-1.52-pkg.tar.gz \
		latin-euro-standards-1.09-pkg.tar.gz \
		latin-unity-1.20-pkg.tar.gz \
		leim-1.31-pkg.tar.gz \
		locale-1.28-pkg.tar.gz \
		lookup-1.15-pkg.tar.gz \
		mail-lib-1.80-pkg.tar.gz \
		mailcrypt-2.14-pkg.tar.gz \
		mew-1.19-pkg.tar.gz \
		mh-e-1.32-pkg.tar.gz \
		mine-1.16-pkg.tar.gz \
		misc-games-1.22-pkg.tar.gz \
		mmm-mode-1.05-pkg.tar.gz \
		mule-base-1.56-pkg.tar.gz \
		mule-ucs-1.18-pkg.tar.gz \
		net-utils-1.56-pkg.tar.gz \
		ocaml-0.06-pkg.tar.gz \
		oo-browser-1.05-pkg.tar.gz \
		os-utils-1.41-pkg.tar.gz \
		pc-1.28-pkg.tar.gz \
		pcl-cvs-1.70-pkg.tar.gz \
		pcomplete-1.06-pkg.tar.gz \
		perl-modes-1.14-pkg.tar.gz \
		pgg-1.07-pkg.tar.gz \
		prog-modes-2.20-pkg.tar.gz \
		ps-print-1.12-pkg.tar.gz \
		psgml-1.45-pkg.tar.gz \
		psgml-dtds-1.03-pkg.tar.gz \
		python-modes-1.14-pkg.tar.gz \
		re-builder-1.05-pkg.tar.gz \
		reftex-1.34-pkg.tar.gz \
		riece-1.23-pkg.tar.gz \
		rmail-1.14-pkg.tar.gz \
		ruby-modes-1.04-pkg.tar.gz \
		sasl-1.16-pkg.tar.gz \
		scheme-1.18-pkg.tar.gz \
		semantic-1.21-pkg.tar.gz \
		sgml-1.11-pkg.tar.gz \
		sh-script-1.24-pkg.tar.gz \
		sieve-1.18-pkg.tar.gz \
		skk-1.24-pkg.tar.gz \
		slider-1.16-pkg.tar.gz \
		sml-mode-0.12-pkg.tar.gz \
		sounds-au-1.12-pkg.tar.gz \
		sounds-wav-1.12-pkg.tar.gz \
		speedbar-1.29-pkg.tar.gz \
		strokes-1.10-pkg.tar.gz \
		supercite-1.21-pkg.tar.gz \
		texinfo-1.30-pkg.tar.gz \
		text-modes-1.98-pkg.tar.gz \
		textools-1.15-pkg.tar.gz \
		time-1.14-pkg.tar.gz \
		tm-1.39-pkg.tar.gz \
		tooltalk-1.15-pkg.tar.gz \
		tpu-1.14-pkg.tar.gz \
		tramp-1.40-pkg.tar.gz \
		vc-1.48-pkg.tar.gz \
		vc-cc-1.22-pkg.tar.gz \
		vhdl-1.22-pkg.tar.gz \
		view-process-1.13-pkg.tar.gz \
		viper-1.67-pkg.tar.gz \
		vm-8.08-pkg.tar.gz \
		w3-1.35-pkg.tar.gz \
		x-symbol-1.11-pkg.tar.gz \
		xemacs-base-2.27-pkg.tar.gz \
		xemacs-devel-1.80-pkg.tar.gz \
		xetla-1.02-pkg.tar.gz \
		xlib-1.14-pkg.tar.gz \
		xslide-1.09-pkg.tar.gz \
		xslt-process-1.12-pkg.tar.gz \
		xwem-1.23-pkg.tar.gz \
		zenirc-1.16-pkg.tar.gz
### DISTFILES

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	Common elisp packages for xemacs 21

DEPENDS+=	xemacs{,-nox11}>=21.1.14:../../editors/xemacs

DIST_SUBDIR=	${PKGBASE}
EXTRACT_DIR=	${WRKDIR}/${PKGBASE}
NO_BUILD=	yes

USE_TOOLS+=	printf pax find gawk gzip
USE_TOOLS+=	perl:run

XEPKGDIR=	lib/xemacs/xemacs-packages

INSTALLATION_DIRS+=	${XEPKGDIR}

FONTS_DIRS.x11+=	${PREFIX}/${XEPKGDIR}/etc/x-symbol/fonts
FONTS_DIRS.x11+=	${PREFIX}/${XEPKGDIR}/etc/x-symbol/origfonts
FONTS_DIRS.x11+=	${PREFIX}/${XEPKGDIR}/etc/x-symbol/pcf

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
ED=	/bin/ed
FTP=	${TOOLS_PATH.ftp:Q}

# Make a list of packages from a directory list output
.PHONY: xemacs-make-package-list
xemacs-fetch-package-list:
	@${ECHO} ls | ${FTP} ftp://ftp.xemacs.org/pub/xemacs/packages/ | \
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
.endif	# PKG_DEVELOPER && OPSYS == "NetBSD"

pre-configure:
	@${ECHO_MSG} "Fixing file permissions ... "
	${CHMOD} -R u+w,go-w ${WRKSRC}
	${CHMOD} g+r,o+r ${WRKSRC}/lisp/auctex/ChangeLog
	${CHMOD} ugo-x ${WRKSRC}/lisp/erc/ChangeLog.2005.upstream
	${FIND} ${WRKSRC} -type f -and -perm -100 \
		-and \( -name "*.el" -or -name "*.gif" -or -name "*.jar" \) \
		-exec ${CHMOD} ugo-x \{\} \;
	@${ECHO_MSG} "done"
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
