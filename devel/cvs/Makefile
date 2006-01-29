# $NetBSD: Makefile,v 1.90 2006/01/29 02:40:40 wiz Exp $
#

DISTNAME=	cvs-1.11.21
CATEGORIES=	devel
MASTER_SITES=	http://ftp.gnu.org/non-gnu/cvs/source/stable/1.11.21/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://cvs.nongnu.org/
COMMENT=	Concurrent Versions System

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GNU_CONFIGURE=	yes

.include "options.mk"

CONFIGURE_ENV+=	perl_path=${PERL5:Q}

INFO_FILES=	cvs.info cvsclient.info
USE_MAKEINFO=	yes
TEXINFO_REQD?=	4.0

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
