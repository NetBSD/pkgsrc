# $NetBSD: Makefile,v 1.27 2022/06/30 11:18:48 nia Exp $

# Date-based distfile name for pre-releases leading to 0.6.6.
DISTNAME=	pyca-20031118
PKGNAME=	${DISTNAME:S/pyca-/pyca-0.6.6./}
PKGREVISION=	6
CATEGORIES=	security python
#MASTER_SITES=	http://www.pyca.de/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.pyca.de/2017/12/31/pyca-x-509-ca/
COMMENT=	Administration tools for X.509/PKIX CA
LICENSE=	gnu-gpl-v2

NO_BUILD=	yes

.include "../../mk/bsd.prefs.mk"

PKG_SYSCONFVAR=			openssl
PKG_SYSCONFSUBDIR=		openssl

.if ${OPSYS} == "NetBSD"
PKG_SYSCONFDIR.openssl?=	/etc/openssl
.endif

REPLACE_PYTHON=	bin/*.py cgi-bin/*.py sbin/*.py

PYCA_SCRIPT_FIXUP_SED= \
	-e "s|/usr/local/pyca/pylib|${PREFIX}/lib/pyca|g"		\
	-e "s|/etc/openssl/openssl.cnf|${PKG_SYSCONFDIR}/openssl.cnf|g"	\
	-e "s|/home/.*/openssl.cnf|${PKG_SYSCONFDIR}/openssl.cnf|g"	\
	-e "s|/home/.*/pylib|${PREFIX}/lib/pyca|g"

INSTALLATION_DIRS=	bin lib/pyca/openssl libexec/cgi-bin sbin \
			share/doc/pyca/help share/doc/pyca/ssi \
			share/examples/pyca

pyca-script-fixup:
	cd ${WRKSRC}; for file in ${REPLACE_PYTHON}; do \
		${SED} ${PYCA_SCRIPT_FIXUP_SED} \
			<$${file} >$${file}.fixed; \
		${MV} $${file}.fixed $${file}; \
	done

post-configure: pyca-script-fixup

do-install:
	cd ${WRKSRC}; for file in bin/*.py; do				\
		${INSTALL_SCRIPT} $${file} ${DESTDIR}${PREFIX}/bin;	\
	done
	cd ${WRKSRC}; for file in cgi-bin/*.py; do			\
		${INSTALL_SCRIPT} $${file} ${DESTDIR}${PREFIX}/libexec/cgi-bin;	\
	done
	cd ${WRKSRC}; for file in sbin/*.py; do				\
		${INSTALL_SCRIPT} $${file} ${DESTDIR}${PREFIX}/sbin;	\
	done
	cd ${WRKSRC}; for file in pylib/*.py; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/lib/pyca;	\
	done
	cd ${WRKSRC}; for file in pylib/openssl/*.py; do		\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/lib/pyca/openssl;	\
	done
	cd ${WRKSRC}; for file in conf/*.cnf; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/examples/pyca;	\
	done
	cd ${WRKSRC}; for file in htdocs/*.html; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/doc/pyca;	\
	done
	cd ${WRKSRC}; for file in htdocs/help/*; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/doc/pyca/help; \
	done
	cd ${WRKSRC}; for file in htdocs/ssi/*.html; do			\
		${INSTALL_DATA} $${file} ${DESTDIR}${PREFIX}/share/doc/pyca/ssi; \
	done

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
