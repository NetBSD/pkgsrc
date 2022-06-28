# $NetBSD: Makefile,v 1.22 2022/06/28 11:34:21 wiz Exp $

DISTNAME=	im-153
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://tats.haun.org/im/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tats.haun.org/im/
COMMENT=	E-Mail and NetNews user interface commands
LICENSE=	modified-bsd

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}
CONFIGURE_ARGS+=	--with-perldir=${PREFIX}/${PERL5_SUB_INSTALLVENDORLIB}
CONFIGURE_ENV+=		im_path_perl=${PERL5:Q}

INSTALL_MAKE_FLAGS+=	sysconfdir=${PREFIX}/share/examples

PKG_SYSCONFSUBDIR=	im

CONF_FILES=	${PREFIX}/share/examples/im/SiteConfig ${PKG_SYSCONFDIR}/SiteConfig

DOCDIR=		${PREFIX}/share/doc/im
EXAMPLESDIR=	${PREFIX}/share/examples/im
DOCS=		00changes 00copyright 00copyright.jis 00perl 00readme 00usage
MAN=		imput
MAN_JA=		imali.jis imcat.jis imcd.jis imclean.jis imget.jis	\
		imhist.jis imjoin.jis immv.jis impack.jis imput.jis	\
		imrm.jis imsetup.jis imsort.jis imstore.jis imtar.jis

INSTALLATION_DIRS+=	${DOCDIR} ${EXAMPLESDIR} ${DOCDIR}/man ${DOCDIR}/man/ja

post-install:
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DESTDIR}${DOCDIR}
.endfor
.for file in ${MAN}
	${INSTALL_DATA} ${WRKSRC}/man/${file} ${DESTDIR}${DOCDIR}/man
.endfor
.for file in ${MAN_JA}
	${INSTALL_DATA} ${WRKSRC}/man/${file} ${DESTDIR}${DOCDIR}/man/ja
.endfor
	${INSTALL_DATA} ${WRKSRC}/dot.im/* ${DESTDIR}${EXAMPLESDIR}

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
