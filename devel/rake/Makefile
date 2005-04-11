# $NetBSD: Makefile,v 1.1.1.1 2005/04/11 04:07:44 minskim Exp $

DISTNAME=	rake-0.5.3
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/3876/
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
