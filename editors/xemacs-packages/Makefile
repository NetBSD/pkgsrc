# $NetBSD: Makefile,v 1.25 2002/03/18 21:17:38 tron Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/22 22:16:53 gj Exp

DISTNAME=	xemacs-packages
PKGNAME=	xemacs-packages-1.8
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/packages/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/packages/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/packages/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/packages/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/packages/ \
		${MASTER_SITE_BACKUP:C|$|${DIST_SUBDIR}|}
DISTFILES=	xemacs-base-1.57-pkg.tar.gz xemacs-devel-1.40-pkg.tar.gz \
		c-support-1.16-pkg.tar.gz cc-mode-1.27-pkg.tar.gz \
		debug-1.14-pkg.tar.gz dired-1.11-pkg.tar.gz \
		edit-utils-1.75-pkg.tar.gz efs-1.27-pkg.tar.gz \
		fsf-compat-1.09-pkg.tar.gz gnus-1.58-pkg.tar.gz \
		mail-lib-1.42-pkg.tar.gz \
		mailcrypt-2.11-pkg.tar.gz mule-base-1.39-pkg.tar.gz \
		net-utils-1.23-pkg.tar.gz os-utils-1.26-pkg.tar.gz \
		prog-modes-1.49-pkg.tar.gz psgml-1.26-pkg.tar.gz \
		sgml-1.08-pkg.tar.gz sh-script-1.13-pkg.tar.gz \
		texinfo-1.20-pkg.tar.gz text-modes-1.36-pkg.tar.gz \
		textools-1.12-pkg.tar.gz time-1.11-pkg.tar.gz \
		vc-1.30-pkg.tar.gz vc-cc-1.18-pkg.tar.gz \
		viper-1.31-pkg.tar.gz

MAINTAINER=	magick@netbsd.org
HOMEPAGE=	http://www.xemacs.org/
COMMENT=	Common elisp packages for xemacs 21

DEPENDS+=	xemacs>=21.1.14:../../editors/xemacs

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_ONLY=	# empty
NO_BUILD=	yes
WRKSRC=		${WRKDIR}

.include "../../mk/bsd.prefs.mk"

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
