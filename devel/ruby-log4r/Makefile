# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:17:37 jlam Exp $

DISTNAME=	log4r-1.0.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel

HOMEPAGE=	http://log4r.sourceforge.net/
COMMENT=	Flexible logging library

GEM_BUILD=	gemspec

# The log4r gem installs the RDoc files under ${GEM_LIBDIR}/doc instead of
# ${GEM_DOCDIR}, so we need to generate the dynamic PLIST entries for
# those files.
#
GENERATE_PLIST+=	\
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${DESTDIR}${PREFIX} && \
	  ${FIND} ${GEM_LIBDIR:S|${PREFIX}/||}/doc \! -type d -print | \
		${SORT} && \
	  ${FIND} ${GEM_LIBDIR:S|${PREFIX}/||}/doc -type d -print | \
		${SORT} -r | ${SED} -e "s,^,@dirrm ," && \
	  ${ECHO} "@dirrm "${GEM_LIBDIR:S|${PREFIX}/||:Q} );

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
