# $NetBSD: Makefile,v 1.25 2009/06/12 23:02:57 minskim Exp $

DISTNAME=	rubygems-1.3.4
PKGREVISION=	1
CATEGORIES=	misc ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/57643/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.rubygems.org/
COMMENT=	Ruby standard for publishing and managing third party libraries

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=	yes
NO_BUILD=	yes
RUBY_REQD=	1.8.7

REPLACE_RUBY_DIRS=	bin
REPLACE_RUBY_PAT=	[a-z]*

GEM_HOME=	${PREFIX}/lib/ruby/gems/${RUBY_VER_DIR}
GEM_DOCDIR=	${GEM_HOME}/doc/${DISTNAME}

REQD_DIRS=	${GEM_HOME:H}
REQD_DIRS+=	${GEM_HOME}
REQD_DIRS+=	${GEM_HOME}/cache
REQD_DIRS+=	${GEM_HOME}/doc
REQD_DIRS+=	${GEM_HOME}/gems
REQD_DIRS+=	${GEM_HOME}/specifications

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-install
SUBST_FILES.conf=	lib/rubygems/config_file.rb
SUBST_SED.conf=		-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"
SUBST_MESSAGE.conf=	Fixing configuration files.


# Generate a dynamic PLIST for the rubygems documentation directory.
GENERATE_PLIST+=	\
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${DESTDIR}${PREFIX} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} \! -type d -print | \
		${SORT} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} -type d -print | \
		${SORT} -r | ${SED} -e "s,^,@dirrm ," );

.include "../../lang/ruby/modules.mk"

# Force the Gem repository to be under ${DESTDIR}.  This is harmless
# because this package depends on no other gems.
#
INSTALL_ENV+=		GEM_HOME=${DESTDIR}${GEM_HOME}
INSTALL_ENV+=		GEM_PATH=${DESTDIR}${GEM_HOME}

INSTALL_TARGET=		install
INSTALL_TARGET+=	--vendor
INSTALL_TARGET+=	--no-format-executable	# "bin/gem", not "bin/gem18"
.if ${_USE_DESTDIR} != "no"
INSTALL_TARGET+=	--destdir=${DESTDIR:Q}
.endif

# rubygem's setup.rb is not the typical setup.rb -- manually run the
# command to install.
#
do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${RUBY} setup.rb ${INSTALL_TARGET}

.include "../../mk/bsd.pkg.mk"
