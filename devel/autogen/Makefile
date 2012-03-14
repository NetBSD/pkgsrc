# $NetBSD: Makefile,v 1.32 2012/03/14 22:51:14 wiz Exp $

DISTNAME=	autogen-5.12
CATEGORIES=	devel
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=autogen/}
MASTER_SITES=	ftp://ftp.gnu.org/gnu/autogen/rel5.12/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kristerw@NetBSD.org
HOMEPAGE=	http://autogen.sourceforge.net/
COMMENT=	The Automated Text and Program Generation Tool
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

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
