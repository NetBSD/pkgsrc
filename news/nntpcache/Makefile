# $NetBSD: Makefile,v 1.18 2004/04/21 21:09:33 cube Exp $
# FreeBSD Id: Makefile,v 1.11 1998/02/01 03:04:11 itojun Exp
#

DISTNAME=		nntpcache-3.0.1
CATEGORIES=		news
MASTER_SITES=		ftp://ftp.nntpcache.org/pub/nntpcache/ \
			ftp://ftp.netlab.is.tsukuba.ac.jp/pub/network/news/nntpcache/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.nntpcache.org/
COMMENT=		NNTP multi-server caching daemon

LICENSE=		fee-based-commercial-use

# enable pgp signed nocem support?
NNTP_USE_PGP?=		no

.if defined(USE_OPENLDAP) && !empty(USE_OPENLDAP:M[Yy][Ee][Ss])
DEPENDS+=		openldap-[0-9]*:../../databases/openldap
.endif

.if ${NNTP_USE_PGP} ==	yes
DEPENDS+=		pgp-2.*:../../security/pgp2
.endif

BUILD_DEFS+=		USE_OPENLDAP NNTP_USE_PGP

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--localstatedir=/var/spool
CONFIGURE_ENV+=		INSTALL_SCRIPT="${INSTALL_SCRIPT}"
USE_GNU_TOOLS+=		make

INSTALL_TARGET=		SUBDIRS="cf src filters http doc pgp contrib/newshound contrib/perlnewshound innreport scripts unixauth" \
			install

post-configure:
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g"  \
		${FILESDIR}/nntpcached.rc > ${WRKSRC}/nntpcached.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nntpcached.sh ${PREFIX}/etc/rc.d/nntpcached
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nntpcache
	cd ${WRKSRC} && ${INSTALL_DATA} README INSTALL FAQ FAQ.html LICENSING \
		README.INN README.pam ChangeLog ${PREFIX}/share/doc/nntpcache/

.include "../../mk/bsd.pkg.mk"
