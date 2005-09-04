# $NetBSD: Makefile,v 1.2 2005/09/04 13:51:33 taca Exp $

DISTNAME=	rake-0.5.4
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/4259/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rake.rubyforge.org/
COMMENT=	Ruby Make

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"

pre-configure:
	${MV} ${WRKSRC}/bin/rake ${WRKSRC}/bin/rake.orig
	${ECHO} "#!${RUBY}" > ${WRKSRC}/bin/rake
	${CAT} ${WRKSRC}/bin/rake.orig >> ${WRKSRC}/bin/rake
	${RM} ${WRKSRC}/bin/rake.orig

.include "../../mk/bsd.pkg.mk"
