# $NetBSD: Makefile,v 1.11 2004/10/03 00:12:53 tv Exp $

DISTNAME=	milter-greylist-1.4
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	manu@netbsd.org
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail

USE_PKGINSTALL=	YES
USE_BUILDLINK3= YES

HAS_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-user=smmsp
CONFIGURE_ARGS+=--with-libspf_alt=${PREFIX}
CONFIGURE_ARGS+=--prefix=${PREFIX}
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

.include "../../mail/libmilter/buildlink3.mk"
.include "../../mail/libspf-alt/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
