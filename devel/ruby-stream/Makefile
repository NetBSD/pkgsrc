# $NetBSD: Makefile,v 1.1.1.1 2006/05/04 01:29:57 minskim Exp $

DISTNAME=	stream-0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	http://rubyforge.org/frs/download.php/639/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rgl.rubyforge.org/stream/
COMMENT=	Interface for external iterators

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/stream
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/stream
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/stream
	${CP} -R ${WRKSRC}/examples/* ${RUBY_EXAMPLESDIR}/stream
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${RUBY_EXAMPLESDIR}/stream
	${FIND} ${RUBY_EXAMPLESDIR}/stream -type d -print |	\
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${RUBY_EXAMPLESDIR}/stream -type f -print |	\
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
