# $NetBSD: setup.py,v 1.2 2002/10/24 12:38:04 drochner Exp $

from distutils.core import setup

setup(
    name="Plex",
    version="1.1.2",
    description="A very nice lexical analysis module for Python",
    
    author="Greg Ewing",
    author_email="greg@cosc.canterbury.ac.nz",
    
    url="http://www.cosc.canterbury.ac.nz/~greg/python/Pyrex/",
    
    packages = ['Plex'],
)
