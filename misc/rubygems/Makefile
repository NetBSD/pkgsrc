# $NetBSD: Makefile,v 1.16 2008/03/12 15:07:47 jlam Exp $

DISTNAME=	rubygems-1.0.1
PKGREVISION=	2
CATEGORIES=	misc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/29548/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubygems.org/
COMMENT=	Ruby standard for publishing and managing third party libraries

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=	yes
NO_BUILD=	yes
RUBY_REQD=	1.8.3

REPLACE_RUBY_DIRS=	${WRKSRC}/bin
REPLACE_RUBY_PAT=	[a-z]*

GEMS_SUBDIR=	lib/ruby/gems/${RUBY_VER_DIR}
REQD_DIRS=	${GEMS_SUBDIR:H}
REQD_DIRS+=	${GEMS_SUBDIR}
REQD_DIRS+=	${GEMS_SUBDIR}/cache
REQD_DIRS+=	${GEMS_SUBDIR}/doc
REQD_DIRS+=	${GEMS_SUBDIR}/gems
REQD_DIRS+=	${GEMS_SUBDIR}/specifications

PLIST_SRC=      ${PKGDIR}/PLIST.common
PLIST_SRC+=     ${WRKDIR}/PLIST_DYNAMIC

.include "../../lang/ruby/modules.mk"

# Force the Gem repository to be under ${DESTDIR}.  This is harmless
# because this packages depends on no other gems.
#
MAKE_ENV+=	GEM_HOME=${DESTDIR}${PREFIX}/${GEMS_SUBDIR}

INSTALL_TARGET=		install
INSTALL_TARGET+=	--format-executable
.if ${_USE_DESTDIR} != "no"
INSTALL_TARGET+=	--buildroot=${DESTDIR:Q}
.endif

# rubygem's setup.rb is not the typical setup.rb -- manually run the
# command to install.
#
do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RUBY} setup.rb		\
		${INSTALL_TARGET}

post-install:
	${RM} -f ${WRKDIR}/PLIST_DYNAMIC
	cd ${DESTDIR}${PREFIX} &&					\
	${FIND} ${GEMS_SUBDIR}/doc/${DISTNAME} \! -type d -print	\
		| ${SORT}						\
		>> ${WRKDIR}/PLIST_DYNAMIC
	cd ${DESTDIR}${PREFIX} &&					\
	${FIND} ${GEMS_SUBDIR}/doc/${DISTNAME} -type d -print		\
		| ${SORT} -r						\
		| ${SED} -e "s/^/@dirrm /"				\
		>> ${WRKDIR}/PLIST_DYNAMIC

.include "../../mk/bsd.pkg.mk"
