# $NetBSD: Makefile,v 1.12 2000/11/25 11:33:04 tron Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1999/06/22 22:16:53 gj Exp

DISTNAME=	xemacs-packages
PKGNAME=	xemacs-packages-1.5
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.xemacs.org/pub/xemacs/packages/ \
		ftp://ftp.mpi-sb.mpg.de/pub/gnu/mirror/ftp.xemacs.org/xemacs/packages/ \
		ftp://ftp.usyd.edu.au/pub/Xemacs/packages/ \
		ftp://ftp.lab.kdd.co.jp/xemacs/packages/ \
		ftp://ftp.th-darmstadt.de/pub/editors/xemacs/packages/
DISTFILES=	xemacs-base-1.46-pkg.tar.gz xemacs-devel-1.30-pkg.tar.gz \
		c-support-1.15-pkg.tar.gz cc-mode-1.21-pkg.tar.gz \
		debug-1.12-pkg.tar.gz dired-1.08-pkg.tar.gz \
		edit-utils-1.53-pkg.tar.gz efs-1.21-pkg.tar.gz \
		fsf-compat-1.07-pkg.tar.gz mail-lib-1.33-pkg.tar.gz \
		mailcrypt-2.06-pkg.tar.gz mule-base-1.35-pkg.tar.gz \
		net-utils-1.14-pkg.tar.gz os-utils-1.24-pkg.tar.gz \
		prog-modes-1.30-pkg.tar.gz psgml-1.20-pkg.tar.gz \
		sgml-1.07-pkg.tar.gz sh-script-1.12-pkg.tar.gz \
		text-modes-1.28-pkg.tar.gz time-1.10-pkg.tar.gz \
		vc-1.24-pkg.tar.gz viper-1.22-pkg.tar.gz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.xemacs.org/

DEPENDS+=	xemacs>=21.1.9:../../editors/xemacs

DIST_SUBDIR=	${PKGNAME}
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
	@${MKDIR} ${PREFIX}/lib/xemacs/xemacs-packages
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
	xargs ${GZIP_CMD}
	@${ECHO_MSG} "done"
.endif

.include "../../mk/bsd.pkg.mk"
