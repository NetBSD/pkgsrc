# $NetBSD: Makefile,v 1.19 2011/12/17 10:15:12 sbd Exp $

.include "../../devel/gettext/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}
PKGREVISION=	3
COMMENT=	Tools for providing messages in different languages

#MAKE_JOBS_SAFE=		no

DISTINFO_FILE=	${.CURDIR}/../../devel/gettext/distinfo
PATCHDIR=	${.CURDIR}/../../devel/gettext/patches

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
CONFIGURE_ARGS+=	--without-included-gettext
CONFIGURE_ARGS+=	--disable-csharp
CONFIGURE_ARGS+=	--without-git
CONFIGURE_ARGS+=	--with-included-libcroco
CONFIGURE_ENV+=		GCJ= ac_cv_prog_GCJ= ac_cv_prog_JAR=
CONFIGURE_ENV+=		HAVE_GCJ_IN_PATH=
CONFIGURE_ENV+=		HAVE_JAVAC_IN_PATH=
CONFIGURE_ENV+=		HAVE_JIKES_IN_PATH=
CONFIGURE_ENV+=		ac_cv_libexpat=no
LDFLAGS.AIX+=		-Wl,-brtl

SHLIBTOOL_OVERRIDE=	# empty
INFO_FILES=		yes

BROKEN_GETTEXT_DETECTION=	yes
USE_BUILTIN.gettext=	no # force use of pkgsrc gettext-lib

post-install:
	cd ${WRKSRC}/gettext-tools/misc && ${MAKE} install DESTDIR=${DESTDIR}
	${INSTALL_MAN} ${WRKSRC}/gettext-tools/man/autopoint.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/gettext-tools/man/gettextize.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/termcap.buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
