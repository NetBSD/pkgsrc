# $NetBSD: Makefile,v 1.108 2024/05/29 16:34:07 adam Exp $

DISTNAME=	tin-2.6.3
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.tin.org/pub/news/clients/tin/stable/
MASTER_SITES+=	https://ftp.funet.fi/pub/unix/news/tin-unoff/
MASTER_SITES+=	ftp://ftp.lip6.fr/pub/unix/news/readers/tin-unoff/
MASTER_SITES+=	ftp://sunsite.icm.edu.pl/pub/unix/news/tin/stable/
#EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tin.org/
COMMENT=	USENET newsreader (termcap based)
# See src/nntplib.c, vms/vms.c
LICENSE=	tin-license

RESTRICTED=		Profit from use, sale, trade, or reproduction disallowed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

INSTALLATION_DIRS=	share/doc/tin

# for tinews.pl
USE_TOOLS+=	msgfmt perl:run pkg-config yacc
REPLACE_PERL=	tools/*.pl
BUILD_TARGET=	build

.include "options.mk"

CONFIGURE_ARGS+=	--with-nntp-default-server=news
CONFIGURE_ARGS+=	--with-mime-default-charset=ISO-8859-1
CONFIGURE_ARGS+=	--enable-break-long-lines
CONFIGURE_ARGS+=	--with-gpg=${PREFIX}/bin/gpg
CONFIGURE_ARGS+=	--with-ispell=${PREFIX}/bin/ispell
CONFIGURE_ARGS+=	--with-metamail=${PREFIX}/bin/metamail
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--disable-mime-strict-charset
CONFIGURE_ARGS+=	--with-defaults-dir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-mh-mail-handling
CONFIGURE_ARGS+=	--with-coffee
CONFIGURE_ARGS+=	--with-zlib

SUBST_CLASSES+=		tin
SUBST_STAGE.tin=	pre-configure
SUBST_MESSAGE.tin=	Adjusting path to the configuration directory.
SUBST_FILES.tin=	doc/tin.1
SUBST_SED.tin=		-e 's:/etc/nntpserver:${PKG_SYSCONFDIR}/nntp/server:'

post-configure:
	${ECHO} '#define NNTP_SERVER_FILE "${PKG_SYSCONFDIR}/nntp/server"' >>${WRKSRC}/include/autoconf.h
	${ECHO} '#define SMTP_SERVER_FILE "${PKG_SYSCONFDIR}/smtpserver"' >>${WRKSRC}/include/autoconf.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/WHATSNEW ${DESTDIR}${PREFIX}/share/doc/tin
	${MV} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/mmdf.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/tin-mmdf.5

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/uulib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
