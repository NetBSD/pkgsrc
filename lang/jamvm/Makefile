# $NetBSD: Makefile,v 1.11 2014/02/08 09:41:29 obache Exp $
#

DISTNAME=		jamvm-1.5.4
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=jamvm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://jamvm.sourceforge.net/
COMMENT=		Compact Java Virtual Machine
LICENSE=		gnu-gpl-v2

DEPENDS+=		classpath>=0.19:../../lang/classpath

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${JAVA_HOME}
GNU_CONFIGURE_MANDIR=	${PREFIX}/${PKGMANDIR}
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes
CONFIGURE_ARGS+=	--with-classpath-install-dir=${PREFIX}/

JAVA_NAME=		jamvm
JAVA_HOME=		${PREFIX}/java/jamvm
JAVA_WRAPPERS+=		java
JAVA_WRAPPER_BIN.java=	${JAVA_HOME}/bin/jamvm
.include "../../devel/libffi/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/java-env.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
