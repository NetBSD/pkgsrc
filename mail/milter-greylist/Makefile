# $NetBSD: Makefile,v 1.7 2004/04/12 13:55:59 tron Exp $

DISTNAME=	milter-greylist-1.0.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@netbsd.rg
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail

USE_PKGINSTALL=	YES
USE_BUILDLINK2= YES

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-user=smmsp --prefix=${PREFIX}
ALL_TARGET=	milter-greylist

PKG_GROUPS=	smmsp
PKG_USERS=	smmsp:smmsp::Sendmail\\ Message\\ Submission\\ Program
RCD_SCRIPTS=	milter-greylist

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/milter-greylist
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/milter-greylist
	${INSTALL_DATA} ${WRKSRC}/greylist.conf \
	  ${PREFIX}/share/examples/milter-greylist

.include "../../mail/libmilter/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
