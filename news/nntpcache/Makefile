# $NetBSD: Makefile,v 1.28 2006/10/17 20:28:01 schwarz Exp $

DISTNAME=		nntpcache-3.0.2
CATEGORIES=		news
MASTER_SITES=		http://www.nntpcache.com/pub/nntpcache/ \
			ftp://ftp.cs.tu-berlin.de/pub/net/news/nntpcache/ \
			ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/news/nntpcache/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.nntpcache.com/
COMMENT=		NNTP multi-server caching daemon

LICENSE=		fee-based-commercial-use

.include "options.mk"

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}/spool
CONFIGURE_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
USE_TOOLS+=		gmake

INSTALL_TARGET=		SUBDIRS="cf src filters http doc pgp contrib/newshound contrib/perlnewshound innreport scripts unixauth" \
			install

post-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/etc/rc.d
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh ${PREFIX}/etc/rc.d/nntpcached
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nntpcache
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL FAQ FAQ.html LICENSING \
		README.INN README.pam ChangeLog ${PREFIX}/share/doc/nntpcache/

.include "../../mk/bsd.pkg.mk"
