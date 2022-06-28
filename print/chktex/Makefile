# $NetBSD: Makefile,v 1.39 2022/06/28 11:35:27 wiz Exp $

DISTNAME=	chktex-1.7.6
PKGREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://download.savannah.gnu.org/releases/chktex/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.nongnu.org/chktex/
COMMENT=	LaTeX semantic checker
LICENSE=	gnu-gpl-v2

DEPENDS+=	lynx-[0-9]*:../../www/lynx

EGDIR=		${PREFIX}/share/examples/chktex
CONF_FILES=	${EGDIR}/chktexrc ${PKG_SYSCONFDIR}/chktexrc

USE_TOOLS+=	gmake perl:run
GNU_CONFIGURE=	YES
CFLAGS+=	-D__unix__
CONFIGURE_ENV+=	PERL5=${PERL5:Q}
MAKE_ENV+=	INSTALL_SCRIPT=${INSTALL_SCRIPT:Q} EGDIR=${EGDIR:Q}

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

INSTALLATION_DIRS+=	${EGDIR}

.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
