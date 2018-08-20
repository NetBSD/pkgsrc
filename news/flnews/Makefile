# $NetBSD: Makefile,v 1.1 2018/08/20 12:57:34 wiz Exp $

DISTNAME=	flnews-0.15
CATEGORIES=	news
MASTER_SITES=	http://micha.freeshell.org/flnews/src/
MASTER_SITES+=	http://www.ybtra.de/flnews-mirror/src/
MASTER_SITES+=	http://www.southcity.de/flnews/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	michael.baeuerle@gmx.net
HOMEPAGE=	http://micha.freeshell.org/flnews/
COMMENT=	Fast and lightweight USENET newsreader with GUI
LICENSE=	modified-bsd AND 2-clause-bsd AND unicode

USE_LANGUAGES=	c c++

NO_CONFIGURE=	yes
TEST_TARGET=	test

# Bug report contact address used for GUI
FLNEWS_MAINTAINER=	${MAINTAINER}

.include "options.mk"

# Old SunPro compilers cannot create dependencies (use makedepend instead)
.if ${OPSYS} == "SunOS" && ${PKGSRC_COMPILER:Msunpro}
FLNEWS_DEP_MD=	1
BUILD_DEPENDS+=	makedepend-[0-9]*:../../devel/makedepend
.endif

# Prepare CONFIG file
SUBST_CLASSES+=			edit-config
SUBST_STAGE.edit-config=	pre-build
SUBST_MESSAGE.edit-config=	Preparing CONFIG file ...
SUBST_FILES.edit-config=	CONFIG
SUBST_SED.edit-config=		-e 's,@PREFIX@,${PREFIX},g'
SUBST_SED.edit-config+=		-e 's,@MAINT@,${FLNEWS_MAINTAINER},g'
SUBST_SED.edit-config+=		-e 's,@IP6@,${FLNEWS_OPT_DISABLE_IP6},g'
SUBST_SED.edit-config+=		-e 's,@NLS@,${FLNEWS_OPT_DISABLE_NLS},g'
SUBST_SED.edit-config+=		-e 's,@XDBE@,${FLNEWS_OPT_DISABLE_XDBE},g'
# NetBSD report X/Open XSI extension as not available (getconf _XOPEN_VERSION)
# but has a sufficient implementation => Force using it
.if ${OPSYS} == "NetBSD"
SUBST_SED.edit-config+=		-e 's,@XSI@,1,g'
.else
SUBST_SED.edit-config+=		-e 's,@XSI@,0,g'
.endif
.if defined(FLNEWS_DEP_MD)
SUBST_SED.edit-config+=		-e 's,@DEP_MD@,,g'
SUBST_SED.edit-config+=		-e 's,@DEP_COMP@,\#,g'
.else
SUBST_SED.edit-config+=		-e 's,@DEP_MD@,\#,g'
SUBST_SED.edit-config+=		-e 's,@DEP_COMP@,,g'
.endif
SUBST_SED.edit-config+=		-e 's,@MAN_PATH@,${PREFIX}/${PKGMANDIR},g'

post-patch:
	${CP} ${FILESDIR}/CONFIG ${WRKSRC}

BUILDLINK_API_DEPENDS.zlib+=	zlib>=1.2.3
.include "../../devel/zlib/buildlink3.mk"
# OpenSSL 1.1 API is required for signature algorithm negotiation
# OpenSSL 1.1 API is required for TLSv1.2 FFDHE group check
BUILDLINK_API_DEPENDS.openssl+=	openssl>=1.0.0
.include "../../security/openssl/buildlink3.mk"
# FLTK must be compiled with multithreading support
# FLTK version 1.4 is supported (should be compiled with pango support)
.include "../../x11/fltk13/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
