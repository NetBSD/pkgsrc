# $NetBSD: Makefile,v 1.15 2004/10/07 05:37:47 rh Exp $
#

DISTNAME=	ispman-0.5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ispman/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.ispman.org/
COMMENT=	ISP management software written in perl

DEPENDS+=	pam-ldap>=77:../../security/pam-ldap
DEPENDS+=	apache>=1.3.14nb1:../../www/apache
DEPENDS+=	p5-ispman>=0.5:../../net/p5-ispman

.if !exists(/usr/sbin/postfix)
DEPENDS+=	{postfix>=20010228,postfix-1.*,postfix-2.*}:../../mail/postfix
.endif

USE_PERL5=	YES

WRKSRC=		${WRKDIR}/ispman
ISPMAN_HTDOCS?=	${PREFIX}/share/ispman/virtual
ISPMAN_IP?=	127.0.0.1

do-configure:
	cd ${WRKSRC} && ${SED} < install.pl > pkginstall.pl		\
		-e 's:@@PREFIX@@:${PREFIX}:g'				\
		-e 's:@@HTDOCS@@:${ISPMAN_HTDOCS}:g'			\
		-e 's:@@IP@@:${ISPMAN_IP}:g'

do-build:
.for dir in ispman-utils ispman-web
	cd ${WRKSRC}/${dir} &&						\
	${RM} -rf `${FIND} . -name CVS -type d -print` &&		\
	for i in `${FIND} . -name '*.orig' -type f -print` ; do		\
		${RM} -f $$i ;						\
	done ;								\
	for i in `${FIND} . -type f -print` ; do			\
		${CP} $$i $$i.old && 					\
		${SED} <$$i.old >$$i -e 's:/usr/bin/perl:${PERL5}:g' &&	\
		${RM} $$i.old ;						\
	done
.endfor

do-install:
	cd ${WRKSRC} && ${PERL5} ./pkginstall.pl &&			\
	${INSTALL_DATA} ispman.ldif ${PREFIX}/etc/ispman

.include "../../mk/bsd.pkg.mk"
