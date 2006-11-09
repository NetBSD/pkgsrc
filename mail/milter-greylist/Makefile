# $NetBSD: Makefile,v 1.25.4.1 2006/11/09 04:58:28 salo Exp $

DISTNAME=	milter-greylist-3.0rc7
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.espci.fr/pub/milter-greylist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://hcpnet.free.fr/milter-greylist/
COMMENT=	Easy-to-use greylist milter for sendmail


GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-user=smmsp

BUILD_TARGET=		milter-greylist

PKG_GROUPS=		smmsp
PKG_USERS=		smmsp:smmsp
PKG_GECOS.smmsp=	Sendmail Message Submission Program

RCD_SCRIPTS=	milter-greylist

.include "options.mk"

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
