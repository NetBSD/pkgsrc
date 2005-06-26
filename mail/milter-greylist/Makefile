# $NetBSD: Makefile,v 1.16 2005/06/26 18:05:25 tron Exp $

DISTNAME=	milter-greylist-2.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail

USE_PKGINSTALL=	YES

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-user=smmsp
CONFIGURE_ARGS+=--with-libspf_alt=${PREFIX}
CONFIGURE_ARGS+=--prefix=${PREFIX}
BUILD_TARGET=	milter-greylist

PKG_GROUPS=	smmsp
PKG_USERS=	smmsp:smmsp::Sendmail\\ Message\\ Submission\\ Program
RCD_SCRIPTS=	milter-greylist

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
	  ${PREFIX}/share/examples/milter-greylist

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libspf-alt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
