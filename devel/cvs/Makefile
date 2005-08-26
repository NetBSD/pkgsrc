# $NetBSD: Makefile,v 1.86 2005/08/26 21:36:28 adrianp Exp $
#

DISTNAME=	cvs-1.11.20
CATEGORIES=	devel
PKGREVISION=	2
# (SSL) download URL according to http://www.cvshome.org/ is
# https://ccvs.cvshome.org/files/documents/19/861/cvs-1.11.20.tar.bz2
MASTER_SITES=	${MASTER_SITE_BACKUP}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.cvshome.org/
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
