# $NetBSD: Makefile,v 1.10 2024/05/16 06:15:07 wiz Exp $

DISTNAME=	mailutils-3.17
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_GNU:=mailutils/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://mailutils.org/
COMMENT=	Utilities, daemons, and filters for processing e-mail
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v3

CONFLICTS+=	elm-[0-9]*		# bin/frm
CONFLICTS+=	avenger-[0-9]*		# bin/dotlock

USE_TOOLS+=	gmake yacc
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
INFO_FILES=	yes

.include "../../mk/bsd.fast.prefs.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/${DOCDIR}
CONFIGURE_ARGS+=	--with-mh-bindir=${PREFIX}/libexec/${PKGBASE}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-mail-spool=/var/spool/mail
.else
CONFIGURE_ARGS+=	--with-mail-spool=/var/mail
.endif
CONFIGURE_ARGS+=	--enable-virtual-domains
CONFIGURE_ARGS+=	--enable-mh

.include "options.mk"

PKG_DOCS=	AUTHORS ChangeLog NEWS README* THANKS TODO
DOCDIR=		share/doc/${PKGBASE}

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	CPPLAGS=${CPPLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
#set-gid files should not be writable by anyone
	${RUN}${CHMOD} -w ${DESTDIR}${PREFIX}/bin/dotlock
	${RUN}${CHMOD} -w ${DESTDIR}${PREFIX}/sbin/mda
	${INSTALL_DATA} ${PKG_DOCS:S|^|${WRKSRC}/|} 		\
		${DESTDIR}${PREFIX}/${DOCDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/libunistring/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
