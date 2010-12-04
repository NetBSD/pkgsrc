# $NetBSD: Makefile,v 1.5 2010/12/04 04:01:06 taca Exp $

DISTNAME=	log4r-1.1.9
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
