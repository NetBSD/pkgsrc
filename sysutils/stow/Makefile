# $NetBSD: Makefile,v 1.37 2025/05/14 05:19:26 wiz Exp $

DISTNAME=	stow-2.4.1
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_GNU:=stow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/stow/stow.html
COMMENT=	Maps several separate packages into a tree without merging them
LICENSE=	gnu-gpl-v3

TEST_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-pmdir=${PERL5_INSTALLVENDORLIB}
USE_TOOLS+=		gmake perl:run
INFO_FILES=		yes
TEST_TARGET=		test

.include "../../mk/bsd.pkg.mk"
