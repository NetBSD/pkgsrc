# $NetBSD: Makefile,v 1.3 1999/01/06 18:04:19 tv Exp $
# $FreeBSD Id: Makefile,v 1.17 1997/06/16 06:39:51 max Exp

DISTNAME=	tinpre-1.4-981225
PKGNAME=	tin-1.4.19981225
CATEGORIES=	news
MASTER_SITES=	ftp://ftp.tin.org/pub/news/clients/tin/current/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/news/tin/pre-v1.4/
EXTRACT_SUFX=	.tgz

MAINTAINER=	udo@keks.franken.de

WRKSRC=		${WRKDIR}/${DISTNAME:S/pre-1.4//}
GNU_CONFIGURE=	yes

# Curses support too buggy to activate
#                 --enable-curses \
#                 --with-ncurses \
#
CONFIGURE_ARGS=	--with-nntp-default-server=news  \
		--with-mime-default-charset=ISO-8859-1 \
		--enable-forgery \
		--enable-break-long-lines \
		--with-ispell=${PREFIX}/bin/ispell \
		--with-metamail=${PREFIX}/bin/metamail \
		--enable-nntp-only \
		--disable-mime-strict-charset \
		--with-defaults-dir=${PREFIX}/etc \
		--with-coffee
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
