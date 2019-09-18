# $NetBSD: Makefile,v 1.14 2019/09/18 11:27:52 adam Exp $

.include "../../devel/thrift/Makefile.version"

COMMENT=	Ruby bindings for the Apache Thrift RPC system
EXTRACT_SUFX=	.tar.gz

EXTRACT_ELEMENTS=	${DISTNAME}/lib/rb

WRKSRC=		${WRKDIR}/${DISTNAME}/lib/rb
GEM_SPECFILE=	${WRKSRC}/thrift.gemspec

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
