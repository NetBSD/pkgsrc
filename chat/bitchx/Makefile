# $NetBSD: Makefile,v 1.15 2003/01/31 00:17:45 salo Exp $
#

DISTNAME=	ircii-pana-1.0c19
PKGNAME=	bitchx-1.0.3.19
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.bitchx.org/pub/BitchX/source/ \
		ftp://ftp.bitchx.org/pub/BitchX/source/old/

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.bitchx.org/
COMMENT=	IRC client based on ircII

WRKSRC=		${WRKDIR}/BitchX

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-ssl

post-patch:
	@${MV} ${WRKSRC}/doc/BitchX.1 ${WRKSRC}/doc/BitchX.1.orig
	@${SED} ${FILES_SUBST_SED} \
		${WRKSRC}/doc/BitchX.1.orig > ${WRKSRC}/doc/BitchX.1

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
