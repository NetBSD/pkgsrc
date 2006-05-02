# $NetBSD: Makefile,v 1.2 2006/05/02 08:59:30 joerg Exp $
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

.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
