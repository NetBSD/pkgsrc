# $NetBSD: Makefile,v 1.1.1.1 2003/09/09 13:55:05 recht Exp $
#

DISTNAME=		postgresql_autodoc-1.12
PKGNAME=		${DISTNAME:S/_/-/}
WRKSRC=			${WRKDIR}/postgresql_autodoc
CATEGORIES=		databases
MASTER_SITES=		http://www.rbt.ca/autodoc/binaries/

MAINTAINER=		recht@NetBSD.org
HOMEPAGE=		http://www.rbt.ca/autodoc/
COMMENT=		Documentation system for PostgreSQL

DEPENDS=		p5-DBD-postgresql-[0-9]*:../../databases/p5-DBD-postgresql
DEPENDS+=		p5-HTML-Template-[0-9]*:../../www/p5-HTML-Template

USE_PERL5=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--datadir=${PREFIX}/share/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
