# $NetBSD: Makefile,v 1.6 2012/03/17 14:40:33 taca Exp $

DISTNAME=	log4r-1.1.10
CATEGORIES=	devel

HOMEPAGE=	http://log4r.rubyforge.org
COMMENT=	Flexible logging library
LICENSE=	gnu-lgpl-v3

# The log4r gem installs the RDoc files under ${GEM_LIBDIR}/doc instead of
# ${GEM_DOCDIR}, so we need to generate the dynamic PLIST entries for
# those files.
#
GENERATE_PLIST+=	\
	${ECHO} "@comment The following lines are automatically generated." && \
	cd ${DESTDIR}${PREFIX} && \
	  ${FIND} ${GEM_LIBDIR:S|${PREFIX}/||}/doc \! -type d -print | \
		${SORT};

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
