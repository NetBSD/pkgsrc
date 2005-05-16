# $NetBSD: Makefile,v 1.46 2005/05/16 01:15:31 jlam Exp $

DISTNAME=	xemacs-packages
PKGNAME=	xemacs-packages-1.15
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=packages/}
DISTFILES=	\
		Sun-1.15-pkg.tar.gz \
		ada-1.14-pkg.tar.gz \
		apel-1.27-pkg.tar.gz \
		auctex-1.36-pkg.tar.gz \
		bbdb-1.24-pkg.tar.gz \
		build-1.14-pkg.tar.gz \
		c-support-1.19-pkg.tar.gz \
		calc-1.24-pkg.tar.gz \
		calendar-1.23-pkg.tar.gz \
		cc-mode-1.42-pkg.tar.gz \
		clearcase-1.08-pkg.tar.gz \
		cookie-1.15-pkg.tar.gz \
		crisp-1.14-pkg.tar.gz \
		debug-1.17-pkg.tar.gz \
		dictionary-1.12-pkg.tar.gz \
		dired-1.15-pkg.tar.gz \
		docbookide-0.07-pkg.tar.gz \
		ecb-1.14-pkg.tar.gz \
		ecrypto-0.16-pkg.tar.gz \
		edebug-1.20-pkg.tar.gz \
		edict-1.16-pkg.tar.gz \
		ediff-1.49-pkg.tar.gz \
		edit-utils-2.11-pkg.tar.gz \
		edt-1.13-pkg.tar.gz \
		efs-1.32-pkg.tar.gz \
		egg-its-1.27-pkg.tar.gz \
		eieio-1.05-pkg.tar.gz \
		elib-1.11-pkg.tar.gz \
		emerge-1.11-pkg.tar.gz \
		erc-0.05-pkg.tar.gz \
		eshell-1.06-pkg.tar.gz \
		ess-1.07-pkg.tar.gz \
		eterm-1.15-pkg.tar.gz \
		eudc-1.39-pkg.tar.gz \
		footnote-1.16-pkg.tar.gz \
		forms-1.15-pkg.tar.gz \
		fortran-modes-1.03-pkg.tar.gz \
		frame-icon-1.11-pkg.tar.gz \
		fsf-compat-1.14-pkg.tar.gz \
		games-1.15-pkg.tar.gz \
		general-docs-1.01-pkg.tar.gz \
		gnats-1.16-pkg.tar.gz \
		gnus-1.79-pkg.tar.gz \
		haskell-mode-1.06-pkg.tar.gz \
		hm--html-menus-1.23-pkg.tar.gz \
		hyperbole-1.15-pkg.tar.gz \
		ibuffer-1.09-pkg.tar.gz \
		idlwave-1.31-pkg.tar.gz \
		igrep-1.12-pkg.tar.gz \
		ilisp-1.33-pkg.tar.gz \
		ispell-1.29-pkg.tar.gz \
		jde-1.46-pkg.tar.gz \
		latin-unity-1.09-pkg.tar.gz \
		leim-1.22-pkg.tar.gz \
		liece-1.13-pkg.tar.gz \
		locale-1.21-pkg.tar.gz \
		lookup-1.14-pkg.tar.gz \
		mail-lib-1.64-pkg.tar.gz \
		mailcrypt-2.14-pkg.tar.gz \
		mew-1.18-pkg.tar.gz \
		mh-e-1.28-pkg.tar.gz \
		mine-1.16-pkg.tar.gz \
		misc-games-1.18-pkg.tar.gz \
		mmm-mode-1.01-pkg.tar.gz \
		mule-base-1.46-pkg.tar.gz \
		mule-ucs-1.05-pkg.tar.gz \
		net-utils-1.38-pkg.tar.gz \
		ocaml-0.05-pkg.tar.gz \
		oo-browser-1.04-pkg.tar.gz \
		os-utils-1.35-pkg.tar.gz \
		pc-1.26-pkg.tar.gz \
		pcl-cvs-1.65-pkg.tar.gz \
		pcomplete-1.03-pkg.tar.gz \
		perl-modes-1.05-pkg.tar.gz \
		pgg-1.04-pkg.tar.gz \
		prog-modes-1.94-pkg.tar.gz \
		ps-print-1.09-pkg.tar.gz \
		psgml-1.42-pkg.tar.gz \
		psgml-dtds-1.03-pkg.tar.gz \
		python-modes-1.03-pkg.tar.gz \
		reftex-1.33-pkg.tar.gz \
		riece-1.14-pkg.tar.gz \
		rmail-1.14-pkg.tar.gz \
		ruby-modes-1.02-pkg.tar.gz \
		sasl-1.14-pkg.tar.gz \
		scheme-1.14-pkg.tar.gz \
		semantic-1.18-pkg.tar.gz \
		sgml-1.11-pkg.tar.gz \
		sh-script-1.18-pkg.tar.gz \
		sieve-1.15-pkg.tar.gz \
		skk-1.23-pkg.tar.gz \
		slider-1.15-pkg.tar.gz \
		sml-mode-0.11-pkg.tar.gz \
		sounds-au-1.12-pkg.tar.gz \
		sounds-wav-1.12-pkg.tar.gz \
		speedbar-1.27-pkg.tar.gz \
		strokes-1.10-pkg.tar.gz \
		supercite-1.20-pkg.tar.gz \
		texinfo-1.25-pkg.tar.gz \
		text-modes-1.73-pkg.tar.gz \
		textools-1.15-pkg.tar.gz \
		time-1.14-pkg.tar.gz \
		tm-1.37-pkg.tar.gz \
		tooltalk-1.15-pkg.tar.gz \
		tpu-1.14-pkg.tar.gz \
		tramp-1.17-pkg.tar.gz \
		vc-1.38-pkg.tar.gz \
		vc-cc-1.22-pkg.tar.gz \
		vhdl-1.18-pkg.tar.gz \
		view-process-1.13-pkg.tar.gz \
		viper-1.37-pkg.tar.gz \
		vm-7.18-pkg.tar.gz \
		w3-1.29-pkg.tar.gz \
		x-symbol-1.09-pkg.tar.gz \
		xemacs-base-1.84-pkg.tar.gz \
		xemacs-devel-1.61-pkg.tar.gz \
		xslide-1.09-pkg.tar.gz \
		xslt-process-1.11-pkg.tar.gz \
		zenirc-1.15-pkg.tar.gz
### DISTFILES

MAINTAINER=	magick@NetBSD.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	Common elisp packages for xemacs 21

DEPENDS+=	xemacs{,-nox11}>=21.1.14:../../editors/xemacs

WRKSRC=		${WRKDIR}
DIST_SUBDIR=	${PKGBASE}
EXTRACT_ONLY=	# empty
NO_BUILD=	yes

PKGSRC_USE_TOOLS+=	gtar

.include "../../editors/xemacs/Makefile.pkg"

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
FTP=	/usr/bin/ftp
PRINTF=	/usr/bin/printf

# Make a list of packages from a directory list output
.PHONY: xemacs-make-package-list
xemacs-fetch-package-list:
	@${ECHO} ls | ${FTP} ftp://ftp.xemacs.org/pub/xemacs/packages/ | \
	${AWK} '/-pkg\.tar\.gz/ { print $$9; }' \
		>${PKGDIR}/packages.list

# Merge package list data into Makefile
.PHONY: xemacs-merge-package-list
xemacs-merge-package-list:
	@{ \
		${SED} '/^DISTFILES/q' ${PKGDIR}/Makefile; \
		${SED} 's|^|		|' ${PKGDIR}/packages.list; \
		${SED} -n '/^### DISTFILES/,$$p' ${PKGDIR}/Makefile; \
	} >${PKGDIR}/Makefile.work
	@{ \
		${PRINTF} '/^DISTFILES\n+1\nka\n/^### DISTFILES\n-2\nkb\n'; \
		${PRINTF} "'a,'b"'s/$$/ \\\\/\nw\nq\n'; \
	} | ${ED} - ${PKGDIR}/Makefile.work

.PHONY: xemacs-update-package
xemacs-update-package: xemacs-fetch-package-list xemacs-merge-package-list
.endif	# PKG_DEVELOPER && OPSYS == "NetBSD"

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/xemacs/xemacs-packages
.for DISTFILE in ${DISTFILES}
	@${ECHO_MSG} -n "Extracting ${DISTFILE} ... "
	@${GTAR} xCzf ${PREFIX}/lib/xemacs/xemacs-packages \
		${DISTDIR}/${DIST_SUBDIR}/${DISTFILE}
	@${ECHO_MSG} "done"
.endfor
	@${ECHO_MSG} -n "Fixing file ownerships ... "
	@${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/lib/xemacs/xemacs-packages
	@${ECHO_MSG} "done"
.if defined(MANZ)
	@${ECHO_MSG} -n "Compressing \".el\" files ... "
	@cd ${PREFIX} && \
		${GREP} '\$${ELSUFX}$$' ${PLIST_SRC} | \
		${SED} -e 's#\$${ELSUFX}$$##' | \
		${XARGS} ${GZIP_CMD}
	@${ECHO_MSG} "done"
.endif

.include "../../mk/bsd.pkg.mk"
