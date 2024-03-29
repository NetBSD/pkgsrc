# $NetBSD: Makefile,v 1.50 2023/12/30 21:16:28 zafer Exp $

DISTNAME=		sqlite-2.8.17
PKGREVISION=		3
CATEGORIES=		databases
MASTER_SITES=		https://www.sqlite.org/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.hwaci.com/sw/sqlite/
COMMENT=		SQL Database Engine in a C Library

USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
OBJDIR=			../sqlite-build
CONFIGURE_ARGS+=	--without-tcl
CONFIGURE_ENV+=		config_TARGET_READLINE_INC="-I${BUILDLINK_PREFIX.editlinereadline}/include"

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == "SunOS")
CFLAGS+=		-DUINT32_TYPE=uint32_t -DUINT16_TYPE=uint16_t \
			-DUINT8_TYPE=uint8_t -DINTPTR_TYPE=long
.else
CFLAGS+=		-DUINT32_TYPE=u_int32_t -DUINT16_TYPE=u_int16_t \
			-DUINT8_TYPE=u_int8_t -DINTPTR_TYPE=long
.endif

PKGCONFIG_OVERRIDE=	sqlite.pc.in

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-extract:
	${RUN} cd ${WRKSRC} && ${MKDIR} ${OBJDIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/sqlite.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/readline.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
