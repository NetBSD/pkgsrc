# $NetBSD: Makefile,v 1.6 1999/03/10 14:05:40 rh Exp $
# FreeBSD Id: Makefile,v 1.11 1998/02/01 03:04:11 itojun Exp
#

DISTNAME=		nntpcache-2.3.3
CATEGORIES=		news
MASTER_SITES=		ftp://nntpcache.org/pub/nntpcache/ \
			ftp://ftp.fu-berlin.de/unix/news/nntpcache/ \
			ftp://ftp.contrib.com/pub/software/unix/news/nntpcache/ \
			ftp://ftp.eu.net/news/transport/nntpcache/ \
			ftp://ftp.belgium.eu.net/pub/news/transport/nntpcache/ \
			ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/news/nntpcache/ \
			ftp://ftp.faho.rwth-aachen.de/pub/linux/nntpcache/ \
			ftp://ftp.hway.ru/pub/news/nntpcache/ \
			ftp://suburbia.net/pub/nntpcache/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.nntpcache.org/

LICENSE=		fee-based-commercial-use

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=/var/spool
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
USE_GMAKE=		yes

INSTALL_TARGET=		SUBDIRS="cf src filters http doc pgp contrib/newshound innreport" \
			install

post-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh ${PREFIX}/etc/rc.d
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nntpcache
	cd ${WRKSRC} && ${INSTALL_DATA} FAQ FAQ.html LICENSING \
		${PREFIX}/share/doc/nntpcache/

.include "../../mk/bsd.pkg.mk"
