# $NetBSD: Makefile,v 1.17 2004/10/03 00:14:43 tv Exp $
#

DISTNAME=		nethack_source_331_jtp_193
PKGNAME=		falcons-eye-1.9.3
PKGREVISION=		4
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=falconseye/}
EXTRACT_SUFX=		.zip

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://falconseye.sourceforge.net/
COMMENT=		Falcon's Eye NetHack

EXTRACT_CMD=		unzip -aq ${DOWNLOADED_DISTFILE}
HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	./sys/unix/setup.sh

WRKSRC=			${WRKDIR}
USE_BUILDLINK3=		yes
USE_X11=		yes

LIBS.SunOS+=		-lm

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	"Configuring program paths."
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	include/config.h src/fe-config.in
SUBST_SED.paths=	-e "s,XXXPREFIXXXX,${PREFIX},g" \
			-e "s,@GZIP_PROGRAM@,${GZIP_CMD:M*gzip},g"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=		unixconf
SUBST_MESSAGE.unixconf=	"Configuring to use NetBSD presets."
SUBST_STAGE.unixconf=	post-patch
SUBST_FILES.unixconf=	include/unixconf.h
SUBST_SED.unixconf=	-e 's,^\/\* \#define BSD 1 \*\/,\#define BSD 1,' \
			-e 's,^\#define SYSV,\/\* \#define SYSV \*\/,' \
			-e 's,^\#define LINUX,\/\* \#define LINUX \*\/,'
.endif

pre-configure:
	${CP} ${WRKSRC}/src/fe-config.in ${WRKSRC}/src/fe-config
	@${CHMOD} 755 ${WRKSRC}/sys/unix/setup.sh

pre-install:
	@${CP} ${WRKSRC}/src/nethack ${WRKSRC}/src/falcons-eye

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/fe-config ${PREFIX}/bin

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
