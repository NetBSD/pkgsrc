# $NetBSD: Makefile,v 1.32 2020/01/18 23:35:21 rillig Exp $
#

DISTNAME=	stow-2.2.2
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_GNU:=stow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/stow/stow.html
COMMENT=	Maps several separate packages into a tree without merging them
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pmdir=${PERL5_INSTALLVENDORLIB}
USE_TOOLS+=		gmake perl:run
INFO_FILES=		yes

.include "../../mk/bsd.pkg.mk"
