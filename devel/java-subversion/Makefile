# $NetBSD: Makefile,v 1.64 2022/06/28 11:31:45 wiz Exp $

PKGNAME=	java-subversion-${SVNVER}
PKGREVISION=	2
COMMENT=	Java bindings for Subversion

MAKE_JOBS_SAFE=	no

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	# empty

USE_TOOLS+=		gmake perl
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
