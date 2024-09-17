# $Id: SCO_SV.mk,v 1.2 2024/09/17 11:52:29 jperkin Exp $

OS = SCO_SV
OS_DEF_FLAG := -D${OS}

CC  ?= gcc
CXX ?= g++
DEV_TOOLS_PREFIX ?= /usr/xdev
FC ?= gfortran
INSTALL ?= /usr/gnu/bin/install
LD ?= gcc

.include "UnixWare.mk"
