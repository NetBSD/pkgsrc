# $NetBSD: Makefile,v 1.12 2001/11/29 01:12:44 hubertf Exp $
# $FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp

DISTNAME=	tin-1.4.5
PKGREVISION=	1
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.tin.org/pub/news/clients/tin/current/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/news/tin/current/ \
		ftp://mirror.aarnet.edu.au/pub/tin/current/ \
		ftp://gd.tuwien.ac.at/infosys/newsreaders/tin/current/ \
		ftp://ftp.funet.fi/pub/unix/news/tin-unoff/ \
		ftp://ftp.nuxi.com/pub/tin/current/ \
		ftp://uiarchive.uiuc.edu/pub/packages/news/client/tin/unoff/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.tin.org/
COMMENT=	TIN newsreader (termcap based)

LICENSE=	no-profit
RESTRICTED=	"Profit from use, sale, trade, or reproduction disallowed"

GNU_CONFIGURE=	yes

.include "../../mk/bsd.prefs.mk"

.if defined(TIN_USE_INN_SPOOL) && ${TIN_USE_INN_SPOOL} == YES
INN_DATA_DIR?=	/var/news
.endif

# Curses support too buggy to activate
#                 --enable-curses \
#                 --with-ncurses \
#
CONFIGURE_ARGS+= --with-nntp-default-server=news  \
		--with-mime-default-charset=ISO-8859-1 \
		--enable-forgery \
		--enable-break-long-lines \
		--with-ispell=${PREFIX}/bin/ispell \
		--with-metamail=${PREFIX}/bin/metamail \
		--disable-mime-strict-charset \
		--with-defaults-dir=${PREFIX}/etc \
		--enable-mh-mail-handling \
		--with-coffee
.if defined(TIN_USE_INN_SPOOL) && ${TIN_USE_INN_SPOOL} == YES
CONFIGURE_ARGS+= --with-inews-dir=${PREFIX}/inn/bin \
		--with-libdir=${INN_DATA_DIR}/db \
		--with-spooldir=${INN_DATA_DIR}/spool/articles \
		--with-nov-dir=${INN_DATA_DIR}/spool/overview
.else
CONFIGURE_ARGS+= --enable-nntp-only
.endif

MAKEFILE=	makefile
ALL_TARGET=	build

post-patch:
	@${MV} ${WRKSRC}/doc/tin.1 ${WRKSRC}/doc/tin.1.dist
	@${SED} -e 's:/etc/nntpserver:${PREFIX}/etc/nntp/server:' \
		<${WRKSRC}/doc/tin.1.dist >${WRKSRC}/doc/tin.1

post-configure:
	${ECHO} '#define NNTP_SERVER_FILE "${PREFIX}/etc/nntp/server"' >>${WRKSRC}/include/autoconf.h
	${ECHO} '#define SMTP_SERVER_FILE "${PREFIX}/etc/smtpserver"' >>${WRKSRC}/include/autoconf.h

.include "../../mk/bsd.pkg.mk"
