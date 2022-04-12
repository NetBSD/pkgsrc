#!/usr/bin/env python

from setuptools import setup

packages = \
['pyparsing', 'pyparsing.diagram']

package_data = \
{'': ['*']}

extras_require = \
{'diagrams': ['railroad-diagrams', 'jinja2']}

setup(name='pyparsing',
      version='3.0.8',
      description='pyparsing module - Classes and methods to define and execute parsing grammars',
      author=None,
      author_email='Paul McGuire <ptmcg.gm+pyparsing@gmail.com>',
      url=None,
      packages=packages,
      package_data=package_data,
      extras_require=extras_require,
      python_requires='>=3.6.8',
     )
