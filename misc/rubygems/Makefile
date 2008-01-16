# $NetBSD: Makefile,v 1.13 2008/01/16 22:56:42 minskim Exp $

DISTNAME=	rubygems-1.0.1
CATEGORIES=	misc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/29548/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubygems.org/
COMMENT=	Ruby standard for publishing and managing third party libraries

NO_CONFIGURE=	yes
NO_BUILD=	yes
INSTALL_TARGET=	install --format-executable
RUBY_REQD=	1.8.3
USE_RUBY_SETUP=	yes

REPLACE_RUBY_DIRS=	${WRKSRC}/bin
REPLACE_RUBY_PAT=	[a-z]*

PLIST_SRC=      ${PKGDIR}/PLIST.common
PLIST_SRC+=     ${WRKDIR}/PLIST_DYNAMIC
PLIST_SRC+=     ${PKGDIR}/PLIST.common_end

.include "../../lang/ruby/modules.mk"

post-install:
	${RM} -f ${WRKDIR}/PLIST_DYNAMIC
	${FIND} ${PREFIX}/lib/ruby/gems/1.8/doc/${DISTNAME}/rdoc	\
		-type f -print						\
		| ${SORT} -r						\
		| ${SED} 's;${PREFIX}/;;g'				\
		>> ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
