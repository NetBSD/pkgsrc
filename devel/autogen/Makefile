# $NetBSD: Makefile,v 1.36 2013/05/31 12:39:57 wiz Exp $

DISTNAME=	autogen-5.12
PKGREVISION=	3
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autogen/}
MASTER_SITES=	ftp://ftp.gnu.org/gnu/autogen/rel5.12/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://autogen.sourceforge.net/
COMMENT=	The Automated Text and Program Generation Tool
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		gmake makeinfo perl:run
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
INFO_FILES=		yes

CONFIGURE_ENV+=	POSIX_SHELL=/bin/sh
MAKE_ENV+=	PERL5=${PERL5} POSIX_CAT=${CAT}

INSTALLATION_DIRS=	include/autoopts

.include "../../lang/guile/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
