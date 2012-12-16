# $NetBSD: Makefile,v 1.18 2012/12/16 01:52:10 obache Exp $

PKGNAME=	java-subversion-${SVNVER}
PKGREVISION=	6
COMMENT=	Java bindings for Subversion

PKG_INSTALLATION_TYPES=	overwrite pkgviews

MAKE_JOBS_SAFE=		no

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	# empty

USE_LANGUAGES+=		c c++
USE_JAVA2=		yes
# We might need PKG_JVM_DEFAULT/PKG_JVMS_ACCEPTED; I'm not much for Java...

CONFIGURE_ARGS+=	--enable-javahl --with-jdk=${PKG_JAVA_HOME}
# To run the tests, uncomment this line if you have junit installed in
# jre/lib/ext .  TODO: If someone packages junit, use that.
#CONFIGURE_ARGS+=	--with-junit

BUILD_TARGET=		javahl
INSTALL_TARGET=		install-javahl
TEST_TARGET=		check-javahl

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
