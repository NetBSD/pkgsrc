# $NetBSD: Makefile,v 1.4 2002/08/26 13:34:16 mjl Exp $

DISTNAME=	gpgme-0.3.9
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/alpha/gpgme/

MAINTAINER=	oishi@ims.ac.jp
HOMEPAGE=	http://www.gnupg.org/gpgme.html
COMMENT=	GnuPG Made Easy

USE_LIBTOOL=	YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

DEPENDS+=	gnupg>=1.0.6:../../security/gnupg

GNU_CONFIGURE=	yes

.include "../../devel/pth/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
