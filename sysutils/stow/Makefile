# $NetBSD: Makefile,v 1.28 2017/01/19 10:37:21 markd Exp $
#

DISTNAME=	stow-2.2.2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_GNU:=stow/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/stow/stow.html
COMMENT=	Maps several separate packages into a tree without merging them

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-pmdir=${PERL5_INSTALLVENDORLIB}
USE_TOOLS+=	gmake perl:run
INFO_FILES=	yes

.include "../../mk/bsd.pkg.mk"
