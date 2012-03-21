# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 22:11:56 mspo Exp $
#

DISTNAME=	percona-toolkit-2.0.4
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/redir/downloads/percona-toolkit/${PKGVERSION}/

MAINTAINER=	msporleder@gmail.com
HOMEPAGE=	http://www.percona.com/software/percona-toolkit/
COMMENT=	Advanced command-line tools for open-source databases (MySQL)
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	perl
PKG_DESTDIR_SUPPORT=	user-destdir
FETCH_USING=		curl

REPLACE_PERL+=	bin/*
CHECK_INTERPRETER_SKIP+=	*pt-ioprofile
CHECK_INTERPRETER_SKIP+=	*pt-mysql-summary
CHECK_INTERPRETER_SKIP+=	*pt-pmp
CHECK_INTERPRETER_SKIP+=	*pt-sift
CHECK_INTERPRETER_SKIP+=	*pt-stalk

DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql
DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes
DEPENDS+=	bash-[0-9]*:../../shells/bash

PERL5_PACKLIST=	auto/percona-toolkit/.packlist
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
