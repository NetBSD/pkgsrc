# $NetBSD: Makefile,v 1.31 2002/11/12 21:11:14 jschauma Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/22 22:16:53 gj Exp

DISTNAME=	xemacs-packages
PKGNAME=	xemacs-packages-1.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/packages/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/packages/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/packages/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/packages/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/packages/ \
		${MASTER_SITE_BACKUP:C|$|${DIST_SUBDIR}/|}
DISTFILES=	Sun-1.13-pkg.tar.gz \
		ada-1.11-pkg.tar.gz \
		apel-1.25-pkg.tar.gz \
		auctex-1.32-pkg.tar.gz \
		bbdb-1.21-pkg.tar.gz \
		build-1.07-pkg.tar.gz \
		c-support-1.16-pkg.tar.gz \
		calc-1.23-pkg.tar.gz \
		calendar-1.19-pkg.tar.gz \
		cc-mode-1.31-pkg.tar.gz \
		clearcase-1.04-pkg.tar.gz \
		cookie-1.14-pkg.tar.gz \
		crisp-1.12-pkg.tar.gz \
		debug-1.16-pkg.tar.gz \
		dictionary-1.11-pkg.tar.gz \
		dired-1.12-pkg.tar.gz \
		docbookide-0.05-pkg.tar.gz \
		ecrypto-0.12-pkg.tar.gz \
		edebug-1.14-pkg.tar.gz \
		edict-1.13-pkg.tar.gz \
		ediff-1.43-pkg.tar.gz \
		edit-utils-1.93-pkg.tar.gz \
		edt-1.12-pkg.tar.gz \
		efs-1.29-pkg.tar.gz \
		egg-its-1.26-pkg.tar.gz \
		eieio-1.03-pkg.tar.gz \
		elib-1.10-pkg.tar.gz \
		emerge-1.09-pkg.tar.gz \
		eshell-1.03-pkg.tar.gz \
		ess-1.02-pkg.tar.gz \
		eterm-1.13-pkg.tar.gz \
		eudc-1.36-pkg.tar.gz \
		footnote-1.15-pkg.tar.gz \
		forms-1.14-pkg.tar.gz \
		frame-icon-1.09-pkg.tar.gz \
		fsf-compat-1.11-pkg.tar.gz \
		games-1.13-pkg.tar.gz \
		gnats-1.15-pkg.tar.gz \
		gnus-1.64-pkg.tar.gz \
		haskell-mode-1.03-pkg.tar.gz \
		hm--html-menus-1.18-pkg.tar.gz \
		ibuffer-1.08-pkg.tar.gz \
		idlwave-1.27-pkg.tar.gz \
		igrep-1.09-pkg.tar.gz \
		ilisp-1.28-pkg.tar.gz \
		ispell-1.24-pkg.tar.gz \
		jde-1.38-pkg.tar.gz \
		latin-unity-1.05-pkg.tar.gz \
		leim-1.19-pkg.tar.gz \
		liece-1.10-pkg.tar.gz \
		locale-1.19-pkg.tar.gz \
		lookup-1.13-pkg.tar.gz \
		mail-lib-1.53-pkg.tar.gz \
		mailcrypt-2.12-pkg.tar.gz \
		mew-1.17-pkg.tar.gz \
		mh-e-1.16-pkg.tar.gz \
		mine-1.14-pkg.tar.gz \
		misc-games-1.15-pkg.tar.gz \
		mmm-mode-1.00-pkg.tar.gz \
		mule-base-1.42-pkg.tar.gz \
		mule-ucs-1.04-pkg.tar.gz \
		net-utils-1.28-pkg.tar.gz \
		ocaml-0.03-pkg.tar.gz \
		os-utils-1.29-pkg.tar.gz \
		pc-1.25-pkg.tar.gz \
		pcl-cvs-1.64-pkg.tar.gz \
		pcomplete-1.02-pkg.tar.gz \
		prog-modes-1.67-pkg.tar.gz \
		ps-print-1.08-pkg.tar.gz \
		psgml-1.35-pkg.tar.gz \
		psgml-dtds-1.02-pkg.tar.gz \
		reftex-1.28-pkg.tar.gz \
		rmail-1.13-pkg.tar.gz \
		sasl-1.12-pkg.tar.gz \
		scheme-1.12-pkg.tar.gz \
		semantic-1.14-pkg.tar.gz \
		sgml-1.08-pkg.tar.gz \
		sh-script-1.16-pkg.tar.gz \
		sieve-1.10-pkg.tar.gz \
		skk-1.23-pkg.tar.gz \
		slider-1.13-pkg.tar.gz \
		sml-mode-0.03-pkg.tar.gz \
		sounds-au-1.10-pkg.tar.gz \
		sounds-wav-1.10-pkg.tar.gz \
		speedbar-1.24-pkg.tar.gz \
		strokes-1.08-pkg.tar.gz \
		supercite-1.19-pkg.tar.gz \
		texinfo-1.21-pkg.tar.gz \
		text-modes-1.53-pkg.tar.gz \
		textools-1.13-pkg.tar.gz \
		time-1.12-pkg.tar.gz \
		tm-1.34-pkg.tar.gz \
		tooltalk-1.13-pkg.tar.gz \
		tpu-1.12-pkg.tar.gz \
		tramp-1.10-pkg.tar.gz \
		vc-1.33-pkg.tar.gz \
		vc-cc-1.21-pkg.tar.gz \
		vhdl-1.15-pkg.tar.gz \
		view-process-1.12-pkg.tar.gz \
		viper-1.35-pkg.tar.gz \
		vm-7.07-pkg.tar.gz \
		w3-1.26-pkg.tar.gz \
		xemacs-base-1.70-pkg.tar.gz \
		xemacs-devel-1.48-pkg.tar.gz \
		xslide-1.03-pkg.tar.gz \
		xslt-process-1.11-pkg.tar.gz \
		zenirc-1.13-pkg.tar.gz

MAINTAINER=	magick@netbsd.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	Common elisp packages for xemacs 21

DEPENDS+=	xemacs>=21.1.14:../../editors/xemacs

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

.include "../../editors/xemacs/Makefile.pkg"

.if defined(MANZ)
PLIST_SUBST+=	ELSUFX=.gz
.else
PLIST_SUBST+=	ELSUFX=
.endif

do-install:
	@${INSTALL_DATA_DIR} ${PREFIX}/lib/xemacs/xemacs-packages
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
.include "../../mk/texinfo.mk"
