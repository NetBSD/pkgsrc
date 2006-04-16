# $NetBSD: Makefile,v 1.1.1.1 2006/04/16 22:16:36 tonio Exp $
#

DISTNAME=		jamvm-1.4.2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jamvm/}

MAINTAINER=		pancake@phreaker.net
HOMEPAGE=		http://jamvm.sourceforge.net/
COMMENT=		Compact Java Virtual Machine

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${JAVA_HOME}
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}
JAVA_HOME=		${PREFIX}/java/jamvm
JAVA_NAME=		jamvm
JAVA_WRAPPERS+=		java
JAVA_WRAPPER_BIN.java=	${JAVA_HOME}/bin/jamvm
CONFIGURE_ARGS+=	--with-classpath-install-dir=${PREFIX}/
USE_TOOLS+=	gmake

DEPENDS+=	classpath>=0.19:../../lang/classpath

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.	if ${MACHINE_ARCH} == "i386"
MACHINE_GNU_PLATFORM=i686-pc-linux-gnu
.	endif
.endif
.if ${OPSYS} == "NetBSD"
MACHINE_GNU_PLATFORM=${MACHINE_ARCH}-foo-openbsd
.endif

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/bsd.pkg.mk"
