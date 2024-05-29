# $NetBSD: Makefile,v 1.19 2024/05/29 19:26:05 schmonz Exp $

DISTNAME=		swagger-codegen-cli-3.0.57
PKGNAME=		${DISTNAME:S/-cli//}
CATEGORIES=		devel
MASTER_SITES=		https://repo1.maven.org/maven2/io/swagger/codegen/v3/swagger-codegen-cli/${PKGVERSION_NOREV}/
EXTRACT_SUFX=		.jar

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://swagger.io/tools/swagger-codegen/
COMMENT=		Generate clients, server stubs, and docs from an OpenAPI spec
LICENSE=		apache-2.0

USE_JAVA=		run
USE_JAVA2=		8
NO_BUILD=		yes
AUTO_MKDIRS=		yes

do-install:
	${INSTALL_DATA} ${WRKSRC}.jar \
		${DESTDIR}${PREFIX}/share/${PKGBASE}/swagger-codegen-cli.jar
	${ECHO} '#!${SH}' > \
		${DESTDIR}${PREFIX}/bin/swagger-codegen
	${ECHO} 'exec java -jar ${PREFIX}/share/${PKGBASE}/swagger-codegen-cli.jar "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/swagger-codegen
	${CHMOD} +x ${DESTDIR}${PREFIX}/bin/swagger-codegen

.include "../../mk/bsd.pkg.mk"
