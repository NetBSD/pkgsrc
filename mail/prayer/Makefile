# $NetBSD: Makefile,v 1.2 2003/01/04 21:29:21 wiz Exp $
#

DISTNAME=	prayer-1.0.5
CATEGORIES=	mail www
MASTER_SITES=	ftp://ftp.csx.cam.ac.uk/pub/software/email/prayer/

MAINTAINER=	abs@netbsd.org
HOMEPAGE=	http://www-uxsup.csx.cam.ac.uk/~dpc22/prayer/
COMMENT=	Small, fast, web mail interface

PKG_GROUPS=	prayer

USE_BUILDLINK2=	YES
USE_GMAKE=	YES
USE_PERL5=	build

.include "../../databases/db4/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mail/imap-uw/buildlink2.mk"
.include "../../security/openssl/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
