# $NetBSD: Makefile,v 1.88 2005/12/02 17:10:04 wiz Exp $
#

DISTNAME=	cvs-1.11.20
CATEGORIES=	devel
PKGREVISION=	2
MASTER_SITES=	http://ftp.gnu.org/non-gnu/cvs/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://cvs.nongnu.org/
COMMENT=	Concurrent Versions System

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

.include "options.mk"

CONFIGURE_ENV+=	perl_path=${PERL5}

INFO_FILES=	cvs.info cvsclient.info
USE_MAKEINFO=	yes
TEXINFO_REQD?=	4.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
