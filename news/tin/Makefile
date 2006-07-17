# $NetBSD: Makefile,v 1.29 2006/07/17 15:48:47 rillig Exp $
#

DISTNAME=	tin-1.8.2
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.tin.org/pub/news/clients/tin/current/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/news/tin/current/ \
		ftp://mirror.aarnet.edu.au/pub/tin/current/ \
		ftp://gd.tuwien.ac.at/infosys/newsreaders/tin/current/ \
		ftp://ftp.funet.fi/pub/unix/news/tin-unoff/ \
		ftp://ftp.nuxi.com/pub/tin/current/ \
		ftp://uiarchive.uiuc.edu/pub/packages/news/client/tin/unoff/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tin.org/
COMMENT=	TIN newsreader (termcap based)

# See src/nntplib.c, vms/vms.c
LICENSE=	no-profit
RESTRICTED=	Profit from use, sale, trade, or reproduction disallowed

GNU_CONFIGURE=	yes
USE_PKGLOCALEDIR=yes
# for tinews.pl
USE_TOOLS+=	perl:run yacc
REPLACE_PERL=	tools/*.pl
BUILD_TARGET=	build

.include "options.mk"

CONFIGURE_ARGS+=	--with-nntp-default-server=news
CONFIGURE_ARGS+=	--with-mime-default-charset=ISO-8859-1
CONFIGURE_ARGS+=	--enable-forgery
CONFIGURE_ARGS+=	--enable-break-long-lines
CONFIGURE_ARGS+=	--with-gpg=${PREFIX}/bin/gpg
CONFIGURE_ARGS+=	--with-ispell=${PREFIX}/bin/ispell
CONFIGURE_ARGS+=	--with-metamail=${PREFIX}/bin/metamail
CONFIGURE_ARGS+=	--with-pcre=${BUILDLINK_PREFIX.pcre}
CONFIGURE_ARGS+=	--disable-mime-strict-charset
CONFIGURE_ARGS+=	--with-defaults-dir=${PREFIX}/etc
CONFIGURE_ARGS+=	--enable-mh-mail-handling
CONFIGURE_ARGS+=	--with-coffee

SUBST_CLASSES+=		tin
SUBST_STAGE.tin=	pre-configure
SUBST_MESSAGE.tin=	Adjusting path to the configuration directory.
SUBST_FILES.tin=	doc/tin.1
SUBST_SED.tin=		-e 's:/etc/nntpserver:${PREFIX}/etc/nntp/server:'

post-configure:
	${ECHO} '#define NNTP_SERVER_FILE "${PREFIX}/etc/nntp/server"' >>${WRKSRC}/include/autoconf.h
	${ECHO} '#define SMTP_SERVER_FILE "${PREFIX}/etc/smtpserver"' >>${WRKSRC}/include/autoconf.h

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tin
	${INSTALL_DATA} ${WRKSRC}/doc/WHATSNEW ${PREFIX}/share/doc/tin

.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/uulib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libidn/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
