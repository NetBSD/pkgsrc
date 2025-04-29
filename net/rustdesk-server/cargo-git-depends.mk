# $NetBSD: cargo-git-depends.mk,v 1.1 2025/04/29 01:53:59 manu Exp $

# Crates taken from HEAD of git repositories.

DISTFILES+= 8d1851d967b1014eb263bae23053a0e513431a9f
SITES.8d1851d967b1014eb263bae23053a0e513431a9f= \
	${MASTER_SITE_GITHUB:=open-trade/}/async-speed-limit/tarball/
EXTRACT.8d1851d967b1014eb263bae23053a0e513431a9f= \
	open-trade-async-speed-limit-8d1851d
VERSION.8d1851d967b1014eb263bae23053a0e513431a9f= async-speed-limit-0.3.1-1

DISTFILES+= 9cb758c9fb2f4edc62eb790acfd45a6a3da21ed3
SITES.9cb758c9fb2f4edc62eb790acfd45a6a3da21ed3= \
	${MASTER_SITE_GITHUB:=rustdesk-org/}/reqwest/tarball/
EXTRACT.9cb758c9fb2f4edc62eb790acfd45a6a3da21ed3= \
	rustdesk-org-reqwest-9cb758c
VERSION.9cb758c9fb2f4edc62eb790acfd45a6a3da21ed3= reqwest-0.11.23

DISTFILES+= 94e97c6d7c93b0bcbfa54f2dc397c1da0a6e43d3
SITES.94e97c6d7c93b0bcbfa54f2dc397c1da0a6e43d3= \
	${MASTER_SITE_GITHUB:=rustdesk-org/}/tokio-socks/tarball/
EXTRACT.94e97c6d7c93b0bcbfa54f2dc397c1da0a6e43d3= \
	rustdesk-org-tokio-socks-94e97c6
VERSION.94e97c6d7c93b0bcbfa54f2dc397c1da0a6e43d3= tokio-socks-0.5.2-1

DISTFILES+= 90b1705d909a4902dbbbdea37ee64db17841077d
SITES.90b1705d909a4902dbbbdea37ee64db17841077d=	\
	${MASTER_SITE_GITHUB:=rustdesk-org/}/sysinfo/tarball/
EXTRACT.90b1705d909a4902dbbbdea37ee64db17841077d= \
	rustdesk-org-sysinfo-90b1705
VERSION.90b1705d909a4902dbbbdea37ee64db17841077d= sysinfo-0.29.10

DISTFILES+= 83db9ec19a2f97e9718aef69e4fc5611bb382479
SITES.83db9ec19a2f97e9718aef69e4fc5611bb382479= \
	${MASTER_SITE_GITHUB:=rustdesk-org/}/confy/tarball/
EXTRACT.83db9ec19a2f97e9718aef69e4fc5611bb382479= rustdesk-org-confy-83db9ec
VERSION.83db9ec19a2f97e9718aef69e4fc5611bb382479= confy-0.4.0-2

DISTFILES+= 78f8f70cd85151a3a2c4a3230d80d5272703c02e
SITES.78f8f70cd85151a3a2c4a3230d80d5272703c02e=	\
	${MASTER_SITE_GITHUB:=rustdesk-org/}/default_net/tarball/
EXTRACT.78f8f70cd85151a3a2c4a3230d80d5272703c02e= \
	rustdesk-org-default_net-78f8f70
VERSION.78f8f70cd85151a3a2c4a3230d80d5272703c02e= default_net-0.1.0

DISTFILES+= 381ff579c1dc3a6c54db9dfec47c44bcb0246542
SITES.381ff579c1dc3a6c54db9dfec47c44bcb0246542=	\
	${MASTER_SITE_GITHUB:=rustdesk-org/}/machine-uid/tarball/
EXTRACT.381ff579c1dc3a6c54db9dfec47c44bcb0246542= \
	rustdesk-org-machine-uid-381ff57
VERSION.381ff579c1dc3a6c54db9dfec47c44bcb0246542= machine-uid-0.3.0
